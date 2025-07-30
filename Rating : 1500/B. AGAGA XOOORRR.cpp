// Problem Link: https://codeforces.com/problemset/problem/1516/B

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

        vector<int> v(n+1);
        for(int i=1; i<=n; i++){
            int x;
            cin>>x;

            v[i] = (v[i-1]^x);
        }

        int ans = 0;
        for(int i=1; i<=n; i++){
            for(int j=i+1; j<n; j++){
                if(v[i] == (v[j]^v[i]) && (v[i] == (v[n]^v[j])))    ans = 1;
            }
        }

        if(ans || v[n] == 0) cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}
