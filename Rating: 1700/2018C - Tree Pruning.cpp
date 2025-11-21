// Problem Link: https://codeforces.com/problemset/problem/2018/C

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void dfs(vector<vector<int>>& adj, int node, int p, vector<int>& par, vector<int>& child){
    for(auto& x: adj[node]){
        if(x == p)    continue;
        par[x] = node;
        dfs(adj, x, node, par, child);
        child[node]++;
    }
}

void bfs(vector<vector<int>>& adj, ll n){
    vector<int> par(n+1, -1), child(n+1, 0);
    dfs(adj, 1, -1, par, child);
    
    int total = n;

    queue<int> qu;
    qu.push(1);

    ll rm = 0, cn = 1, ans = total-cn;
    while(qu.size()){
        int sz = qu.size();

        while(sz--){
            int node = qu.front();
            qu.pop();

            if(child[node] == 0){
                while(par[node] != -1 && child[node] == 0){
                    rm++;
                    node = par[node];
                    child[node]--;
                }
            }
            else{
                for(auto& x: adj[node]){
                    if(x == par[node])  continue;
                    qu.push(x);
                    cn++;
                }
            }
        }
        ans = min(ans, rm + total - cn);
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<vector<int>> adj(n+1);
        for(int i=1; i<n; i++){
            int u,v;
            cin>>u>>v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bfs(adj, n);
        
    }

    return 0;
}
