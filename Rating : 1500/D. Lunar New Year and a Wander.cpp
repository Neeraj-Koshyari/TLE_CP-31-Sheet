// Problem Link: https://codeforces.com/problemset/problem/1106/D

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9+7;

vector<int> bfs(vector<vector<int>>& adj, int n){
    vector<int> ans, vis(n);

    set<int> st;
    st.insert(0);

    while(st.size()){
        int node = *st.begin();
        st.erase(st.begin());

        vis[node] = 1;
        ans.push_back(node+1);

        for(auto& x:adj[node]){
            if(!vis[x]) st.insert(x);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin>>n>>m;

    vector<vector<int>> adj(n);
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;

        u--;
        v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans = bfs(adj, n);

    for(auto& x:ans)    cout<<x<<" ";

    return 0;
}
