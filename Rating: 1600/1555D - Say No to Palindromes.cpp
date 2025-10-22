// Problem Link: https://codeforces.com/problemset/problem/1555/D

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> ans(6);
    ans[0] = "abc";
    ans[1] = "acb";
    ans[2] = "bac";
    ans[3] = "bca";
    ans[4] = "cab";
    ans[5] = "cba";

    int n,q;
    cin>>n>>q;

    string s;
    cin>>s;

    vector<vector<int>> pref(6, vector<int>(n+1));
    for(int i=0; i<6; i++){
        for(int j=1; j<=n; j++){
            if(s[j-1] != ans[i][(j-1)%3])   pref[i][j]++;
            pref[i][j] += pref[i][j-1];
            // cout<<pref[i][j]<<" ";
        }
        // cout<<endl;
    }

    while(q--){
        int l, r, cost = n;
        cin>>l>>r;

        for(int i=0; i<6; i++)
            cost = min(cost, pref[i][r] - pref[i][l-1]);
        
        cout<<cost<<endl;
    }
}
