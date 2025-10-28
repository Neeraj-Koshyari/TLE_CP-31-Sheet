// Problem Link: https://codeforces.com/problemset/problem/1475/E

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll find(ll x, ll y, ll mod){
    ll ans = 1;
    while(y){
        if(y&1) ans = (ans * x)%mod;

        y/=2;
        x = (x * x)%mod;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 1e3+1, mod = 1e9+7;
    vector<ll> fact(N);

    fact[0] = fact[1] = 1;
    for(ll i=2; i<N; i++)   fact[i] = (i * fact[i-1])%mod;
    

    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;

        vector<ll> v(n+1);
        for(int i=0; i<n; i++){
            int x;
            cin>>x;

            v[x]++;
        }

        int total_freq = 0, space_left = 0, count = k;
        for(int i=n; i>0; i--){
            if(v[i] > count){
                total_freq = v[i];
                space_left = count;
                break;
            }
            count -= v[i];
        }

        ll deno = (fact[space_left] * fact[total_freq - space_left])%mod;
        ll ans = (fact[total_freq] * find(deno, mod-2, mod))%mod;
        cout<<ans<<endl;
    }
}
