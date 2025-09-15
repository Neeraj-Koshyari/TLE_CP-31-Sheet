// Problem Link: https://codeforces.com/problemset/problem/1843/E

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool find(int x, int n, vector<vector<int>>& v, vector<int>& qry){
    int m = v.size(), q = qry.size();
    
    vector<int> temp(n+1);
    for(int i=0; i<=x; i++) temp[qry[i]] = 1;

    for(int i=1; i<=n; i++)  temp[i] += temp[i-1];

    for(auto& pr:v){
        int len = pr[1]-pr[0]+1;
        int one = temp[pr[1]] - temp[pr[0]-1];
        if(one > (len/2))   return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--){
        int n,m;
        cin>>n>>m;

        vector<vector<int>> v(m,vector<int>(2));
        for(int i=0; i<m; i++)  cin>>v[i][0]>>v[i][1];

        int q;
        cin>>q;

        vector<int> qry(q);
        for(int i=0; i<q; i++)  cin>>qry[i];

        int l = -1, r = q;
        while(l+1 < r){
            int mid = (l+r)/2;

            if(find(mid, n, v, qry))   r = mid;
            else l = mid;
        }

        if(r == q)  cout<<-1<<endl;
        else cout<<r+1<<endl;
    }
    

    return 0;
}
