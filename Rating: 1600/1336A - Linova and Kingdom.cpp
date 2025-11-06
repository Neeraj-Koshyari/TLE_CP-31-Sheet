// Problem Link: https://codeforces.com/problemset/problem/1336/A

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll dfs(int node, int par, vector<vector<int>>& adj, int dpt, vector<ll>& v){
    ll child = 0;
    for(auto& x: adj[node]){
        if(x == par)    continue;
        child += dfs(x, node, adj, dpt+1, v);
    }

    v[node] = child - dpt;
    return child+1;
}

int cmp(int a,int b){return a>b;}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin>>n>>k;

    vector<vector<int>> adj(n+1);
    for(int i=1; i<n; i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<ll> v(n+1);
    dfs(1, -1, adj, 0, v);

    std::nth_element(v.begin()+1,v.begin()+n-k,v.begin()+n+1,cmp);
    
    ll sum = 0;
    for(int i=0; i<=(n-k); i++)  sum += v[i];

    cout<<sum<<endl;
    return 0;
}
