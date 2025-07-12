// Problem Link: https://codeforces.com/problemset/problem/1881/E


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

        vector<int> v(n), dp(n+1);
        for(int i=0; i<n; i++)  cin>>v[i];

        for(int i = n-1; i>=0; i--){
            int idx = i + v[i] + 1;
            if(idx > n)    dp[i] = dp[i+1] + 1;
            else    dp[i] = min(dp[idx], dp[i+1] + 1);
        }

        cout<<dp[0]<<endl;
    }

    return 0;
}
