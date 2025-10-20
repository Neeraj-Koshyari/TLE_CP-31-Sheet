// Problem Link: https://codeforces.com/problemset/problem/1633/D

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll find(vector<ll>& b, vector<ll>& c, int idx, int k, vector<ll>& move, vector<vector<ll>>& dp){
    if(idx < 0) return 0;

    if(dp[idx][k] != -1)  return dp[idx][k];

    ll req = move[b[idx]], take = 0;
    if(req <= k)    take = c[idx] + find(b, c, idx-1, k-req, move, dp);
    ll not_take = find(b, c, idx-1, k, move, dp);

    return dp[idx][k] = max(take, not_take);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 1000;
    vector<ll> move(N + 1, INT_MAX);
    queue<int> q;
    move[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        int prevd = -1;
        for (int x = 1; x <= cur; ++x) {
            int d = cur / x;
            if (d == 0) break;
            if (d == prevd) continue;
            prevd = d;
            int nxt = cur + d;
            if (nxt > N) continue;
            if (move[nxt] > move[cur] + 1) {
                move[nxt] = move[cur] + 1;
                q.push(nxt);
            }
        }
    }


    // ll sum = 0;
    // for(int i=1; i<N; i++)  sum += move[i];
    // cout<<sum<<endl;

    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;

        k = min(k, 12000);

        vector<vector<ll>> dp(n+1, vector<ll>(k+1, -1));
        vector<ll> b(n), c(n);
        for(int i=0; i<n; i++)  cin>>b[i];
        for(int i=0; i<n; i++)  cin>>c[i];

        cout<<find(b,c,n-1,k,move, dp)<<endl;
    }
}
