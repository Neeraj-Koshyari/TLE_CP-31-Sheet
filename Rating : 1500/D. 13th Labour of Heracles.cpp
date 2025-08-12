// Problem Link: https://codeforces.com/problemset/problem/1466/D

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
	cin>>t;
	
	while(t--){
        int n;
        cin>>n;

        vector<ll> wt(n+1), deg(n+1);
        for(int i=1; i<=n; i++)  cin>>wt[i];

        for(int i=1; i<n; i++){
            int u,v;
            cin>>u>>v;

            deg[u]++;
            deg[v]++;
        }

        ll ans = 0;
        vector<ll> v;

        for(int i=1; i<=n; i++){
            for(int j=1; j<deg[i]; j++) v.push_back(wt[i]);
            ans += wt[i];
        }

        sort(v.rbegin(), v.rend());
        
        for(auto& x:v){
            cout<<ans<<" ";
            ans += x;
        }
        cout<<ans<<endl;
    }

    return 0;
}
