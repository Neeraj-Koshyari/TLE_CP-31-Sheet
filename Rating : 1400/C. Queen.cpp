// Problem Link: https://codeforces.com/problemset/problem/1143/C

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void dfs(int node, vector<vector<int>>& adj, vector<int>& resp, vector<int>& ans){
    int respect = 1;

    if(resp[node] == 1){
        for(auto& x : adj[node]){
            if(resp[x] == 0){
                respect = 0;
                break;
            }
        }
        if(respect == 1)    ans.push_back(node);
    }

    for(auto& x: adj[node]){
        dfs(x, adj, resp, ans);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, root = 0;
    cin>>n;

    vector<vector<int>> adj(n+1);
    vector<int> resp(n+1);

    for(int i=1; i<=n; i++){
        int x, c;
        cin>>x>>c;

        if(x == -1) root = i;
        else adj[x].push_back(i);

        resp[i] = c;
    }

    vector<int> ans;
    dfs(root, adj, resp, ans);

    if(ans.size() == 0) cout<<-1<<endl;
    else{
        sort(ans.begin(), ans.end());
        for(auto& x: ans)   cout<<x<<" ";
    }
    
    return 0;
}
