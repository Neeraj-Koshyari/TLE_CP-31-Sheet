// Problem Link: https://codeforces.com/problemset/problem/1519/C

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> v(n);
        map<int,vector<ll>> mp;
        for(int i=0;i<n;i++)    cin>>v[i];
        for(int i=0;i<n;i++){
            ll x;
            cin>>x;
            if(mp[v[i]].size() == 0)    mp[v[i]].push_back(0);
            mp[v[i]].push_back(x);
        }

        vector<ll> ans(n+1);
        for(auto& x:mp){
            sort(x.second.begin(), x.second.end());

            int m = x.second.size();
            for(int i=1; i<m; i++)  x.second[i] += x.second[i-1];
            for(int i=1; i<m; i++){
                int idx = (m-1)%i;
                ans[i] += x.second[m-1] - x.second[idx];
            }
        }

        for(int i=1;i<=n;i++)   cout<<ans[i]<<" ";
        cout<<endl;
    }

    return 0;
}
