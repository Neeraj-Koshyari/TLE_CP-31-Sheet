// Problem Link: https://codeforces.com/problemset/problem/1795/D

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll mulinv(ll x, ll y, ll mod){
    ll ans = 1;
    while(y){
        if(y&1) ans = (ans*x)%mod;

        x = (x*x)%mod;
        y/=2;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    ll ans = 1, mod = 998244353;
    for(int i=1; i<=n/6; i++){
        ll val = ((i+n/6) * mulinv(i, mod-2, mod))%mod;    // (n/3)! / (n/6)!
        ans = (ans * val)%mod;
    }

    for(int i=0; i<n/3; i++){
        ll arr[3], mn = 1e9, count = 0;
        for(int j=0; j<3; j++){
            cin>>arr[j];
            mn = min(mn, arr[j]);
        }

        for(int j=0; j<3; j++){
            if(arr[j] == mn)    count++;
        }

        ans = (ans * count)%mod;
    }
    cout<<ans<<endl;
    

    return 0;
}
