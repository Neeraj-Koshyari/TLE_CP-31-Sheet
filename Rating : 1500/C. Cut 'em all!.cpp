// Problem Link: https://codeforces.com/contest/982/problem/C

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int dfs(int node, vector<vector<int>>& adj, vector<int>& child, int par){

    int count = 0;
    for(auto& x: adj[node]){
        if(x == par)    continue;

        count += dfs(x, adj, child, node);
        child[node] += child[x];

        if(child[x] % 2 == 0)   count++;
    }

    child[node]++;
    return count;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<vector<int>> adj(n);
    for(int i=1; i<n; i++){
        int u,v;
        cin>>u>>v;

        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    if(n&1){
        cout<<-1<<endl;
        return 0;
    }

    vector<int> child(n);
    cout<<dfs(0, adj, child, -1)<<endl;    

    return 0;
}
