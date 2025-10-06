// Problem Link: https://codeforces.com/problemset/problem/1741/E

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> v(n+1), dp(n+1,0);
        for(int i=1; i<=n; i++)  cin>>v[i];

        dp[0] = 1;
        for(int i=1; i<=n; i++){
            if(i+v[i] <= n && dp[i-1])  dp[i + v[i]] = 1;
            if(i-v[i]-1 >= 0 && dp[i-v[i]-1])   dp[i] = 1;
        }
        if(dp[n])   cout<<"YES\n";
        else cout<<"NO\n";
    }
}
