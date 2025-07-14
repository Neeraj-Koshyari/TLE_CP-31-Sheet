// Problem Link: https://codeforces.com/problemset/problem/1673/C

// Hint: Think the problem as Coin Combinations problem, Where we can use only palindrome coin numbers.

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll mod = 1e9+7;

bool isPalin(int x){
    int val = x, y = 0;
    while(val){
        y = y*10 + val%10;
        val /= 10;
    }
    return x == y;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> palin;
    palin.push_back(0);
    
    int N = 4e4+1;
    for(int i=1; i<N; i++){
        if(isPalin(i))  palin.push_back(i);
    }

    int M = palin.size();

    vector<vector<int>> dp(N, vector<int>(M,0));
    for(int j=0; j<M; j++) dp[0][j] = 1;

    for(int i=1; i<N; i++){
        for(int j=1; j<M; j++){
            if(palin[j] <= i)   dp[i][j] = (dp[i][j-1] + dp[i-palin[j]][j])%mod;
            else dp[i][j] = dp[i][j-1];
        }
    }

    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;

        cout<<dp[n][M-1]<<endl;
    }

    return 0;
}
