// Problem Link: https://codeforces.com/problemset/problem/414/B

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int mod = 1e9+7;

ll find(int n, int k, int last, vector<vector<ll>>& dp){
    if(k == 1)  return n/last;

    if(dp[k][last] != -1)   return dp[k][last];

    ll ans = 0;
    for(int i=last; i<=n; i += last){
        ans = (ans + find(n, k-1, i, dp))%mod;
    }
    return dp[k][last] = ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin>>n>>k;

    vector<vector<ll>> dp(k+1, vector<ll>(n+1,-1));
    cout<<find(n, k, 1, dp)<<endl;

    return 0;
}
