// Problem Link: https://codeforces.com/problemset/problem/1498/C

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll mod = 1e9+7;
    int t;
    cin>>t;

    while(t--){
        ll n,k;
        cin>>n>>k;

        vector<ll> v(n+2);
        v[0] = 1;

        ll ans = 1;
        k -= 1;
        while(k--){
            vector<ll> temp(n+2);
            for(int i=1; i<=n; i++){
                temp[i] = (temp[i-1] + v[i-1])%mod;
                ans = (ans + temp[i])%mod;
            }

            reverse(temp.begin(), temp.end());
            v = temp;
        }
        cout<<ans<<endl;
    }
}
