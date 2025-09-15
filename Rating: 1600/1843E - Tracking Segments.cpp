// Problem Link: https://codeforces.com/problemset/problem/1843/E

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void update(int idx, int l, int r, int k, int u, vector<int>& seg){
	if(l == r){	
		seg[idx] = u;
		return;
	}

	int mid = (l+r)/2;
	if(k<=mid)	update(2*idx+1, l, mid, k, u, seg);
	else update(2*idx+2,mid+1, r, k, u, seg);

	seg[idx] = seg[2*idx + 1] + seg[2*idx + 2];
}

int query(int idx, int l, int r, int qL, int qR, vector<int>& seg){

	if(l >= qL && r <= qR)	return seg[idx];	//if current segment completly lies in finding segment

	if(r<qL || qR<l)	return 0;		// if current segment dosent lies

	// partial overlapping, Then check in left and right
	int mid = (l+r)/2;
	long long left = query(2*idx+1,l,mid,qL,qR,seg);
	long long right = query(2*idx+2,mid+1,r,qL,qR,seg);

	return left + right;
}

bool find(int x, int n, vector<int>& seg, vector<vector<int>>& v, vector<int>& qry){
    int m = v.size(), q = qry.size(), flag = 0;

    for(int i=0; i<=x; i++)
        update(0, 0, n-1,  qry[i]-1, 1, seg);

    for(auto& pr : v){
        int val = query(0, 0, n-1, pr[0]-1, pr[1]-1, seg);
        int len = pr[1] - pr[0] + 1;
        if(val > (len/2))   flag = 1;
    }

    for(int i=0; i<=x; i++)
        update(0, 0, n-1,  qry[i]-1, 0, seg);
    
    return (flag == 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--){
        int n,m;
        cin>>n>>m;

        vector<int> seg(4*n);
        vector<vector<int>> v(m,vector<int>(2));
        for(int i=0; i<m; i++)  cin>>v[i][0]>>v[i][1];

        int q;
        cin>>q;

        vector<int> qry(q);
        for(int i=0; i<q; i++)  cin>>qry[i];

        int l = -1, r = q;
        while(l+1 < r){
            int mid = (l+r)/2;

            if(find(mid, n, seg, v, qry))   r = mid;
            else l = mid;
        }

        if(r == q)  cout<<-1<<endl;
        else cout<<r+1<<endl;
    }
    

    return 0;
}
