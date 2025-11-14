// Problem Link: https://codeforces.com/problemset/problem/2050/F

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void build(int idx,int l, int r,vector<int>& v, vector<int>& seg){
	if(l == r){
		seg[idx] = v[l];
		return;
	}

	int mid = (l+r)/2;
	build(2*idx+1, l, mid, v, seg);
	build(2*idx+2, mid+1, r, v, seg);

	seg[idx] = gcd(seg[2*idx+1], seg[2*idx+2]);
}

int query(int idx, int l, int r, int qL, int qR, vector<int>& seg){

	if(l >= qL && r <= qR)	return seg[idx];

	if(r<qL || qR<l)	return 0;

	int mid = (l+r)/2;
	int left = query(2*idx+1,l,mid,qL,qR,seg);
	int right = query(2*idx+2,mid+1,r,qL,qR,seg);

	return gcd(left, right);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--){
        int n,q;
        cin>>n>>q;

        vector<int> v(n), seg(4*n);
        for(int i=0; i<n; i++)  cin>>v[i];

        for(int i=0; i<n-1; i++)  v[i] = abs(v[i]-v[i+1]);
        v[n-1] = 0;

        build(0, 0, n-1, v, seg);

        while(q--){
            int x, y;
            cin>>x>>y;
            if(x == y){
                cout<<0<<" ";
                continue;
            }

            x -= 1;
            y -= 2;
            cout<<query(0, 0, n-1, x, y, seg)<<" ";
        }
        cout<<endl;
    }

    
    return 0;
}
