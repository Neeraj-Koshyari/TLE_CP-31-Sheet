// Problem Link: https://codeforces.com/problemset/problem/1528/A

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void find(ll node, vector<vector<ll>>& wt, vector<vector<ll>>& adj, ll par, vector<vector<ll>>& dp){
    ll ans1 = 0, ans2 = 0;

    for(auto& x: adj[node]){
        if(x == par)    continue;
        find(x, wt, adj, node, dp);
    }

    for(auto& x: adj[node]){
        if(x == par)    continue;

        ll diff1 = abs(wt[node][0] - wt[x][0]) + dp[x][0];
        ll diff2 = abs(wt[node][0] - wt[x][1]) + dp[x][1];

        ans1 += max(diff1, diff2);
    }

    for(auto& x: adj[node]){
        if(x == par)    continue;

        ll diff1 = abs(wt[node][1] - wt[x][0]) + dp[x][0];
        ll diff2 = abs(wt[node][1] - wt[x][1]) + dp[x][1];

        ans2 += max(diff1, diff2);
    }
    dp[node][0] = ans1;
    dp[node][1] = ans2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<vector<ll>> wt(n+1, vector<ll>(2)), adj(n+1), dp(n+1, vector<ll>(2));
        for(int i=1; i<=n; i++)  cin>>wt[i][0]>>wt[i][1];

        for(int i=1; i<n; i++){
            ll u, v;
            cin>>u>>v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        find(1, wt, adj, -1, dp);
        cout<<max(dp[1][0], dp[1][1])<<endl;
    }
}
