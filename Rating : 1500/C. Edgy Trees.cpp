// Problem Link: https://codeforces.com/problemset/problem/1139/C

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9+7;

ll power(ll x, int y){
    ll ans = 1;
    while(y){
        if(y&1) ans = (ans*x)%mod;

        x = (x*x)%mod;
        y /= 2;
    }
    return ans;
}

ll dfs(int node, vector<vector<vector<int>>>& adj, vector<int>& vis, int par){
    vis[node] = 1;

    ll count = 1;
    for(auto& x:adj[node]){
        if(vis[x[0]] == 1 || x[0] == par || x[1] == 1)    continue;

        count += dfs(x[0], adj, vis, node);
    }

    return count;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin>>n>>k;

    ll total = power(n,k);

    vector<vector<vector<int>>> adj(n);
    for (int i = 1; i < n; i++){
        int u,v,x;
        cin>>u>>v>>x;

        u--;
        v--;

        adj[u].push_back({v,x});
        adj[v].push_back({u,x});
    }

    vector<int> vis(n);
    for(int i=0; i<n; i++){
        if(vis[i] != 0) continue;

        ll val = dfs(i, adj, vis, -1);
        total = (total - power(val,k) + mod)%mod;
    }
    cout<<total<<endl;
    

    return 0;
}
