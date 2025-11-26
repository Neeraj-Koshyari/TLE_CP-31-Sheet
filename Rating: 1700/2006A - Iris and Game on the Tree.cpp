// Problem Link: https://codeforces.com/problemset/problem/2006/A

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

        vector<vector<int>> adj(n+1);
        
        for(int i=1; i<n; i++){
            int u, v;
            cin>>u>>v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        string s;
        cin>>s;

        int one = 0, zero = 0, other = 0, totalOther = 0;
        for(int i=1; i<=n; i++){
            if(s[i] == '?') totalOther++;
            if(i == 1 || adj[i].size() != 1)  continue;

            if(s[i-1] == '?'){
                other++;
                totalOther--;
            }
            else if(s[i-1] == '1')  one++;
            else zero++;
        }

        int ans = 0;
        if(s[0] == '0') ans = one + (other+1)/2;
        else if(s[0] == '1')    ans = zero + (other+1)/2;
        else{
            if(one == zero && other&1){
                if(totalOther&1)    ans = one + (other + 1)/2;
                else ans = one + other/2;
            }
            else    ans = max(one, zero) + other/2;
        }

        cout<<ans<<endl;
    }

    return 0;
}
