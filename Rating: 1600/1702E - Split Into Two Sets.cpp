// Problem Link: https://codeforces.com/problemset/problem/1702/E

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isBiparted(vector<vector<int>>& adj, int node, vector<int>& color, int clr){
    color[node] = clr;
    for(auto& x: adj[node]){
        if(color[x] == -1){
            if(!isBiparted(adj, x, color, 1-clr))   return false;
        }
        else if(color[x] == clr)    return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--){
        int n, flag = 1;
        cin>>n;

        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++){  
            int u, v;
            cin>>u>>v;
            
            u--;
            v--;
            
            adj[u].push_back(v);
            adj[v].push_back(u);

            if(u == v || adj[u].size() > 2 || adj[v].size() > 2)    flag = 0;
        }

        if(flag == 0){
            cout<<"NO\n";
            continue;
        }

        vector<int> color(n, -1);
        for(int i=0; i<n; i++){
            if(color[i] != -1)  continue;

            if(!isBiparted(adj,i,color,0)){
                flag = 0;
                break;
            }
        }

        if(flag)    cout<<"YES\n";
        else cout<<"NO\n";
    }
}
