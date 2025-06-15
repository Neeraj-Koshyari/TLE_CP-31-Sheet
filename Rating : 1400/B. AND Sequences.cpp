// Problem Link: https://codeforces.com/problemset/problem/1513/B

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll mod = 1e9+7, N = 2e5+1;
    vector<ll> fact(N);
    fact[0] = fact[1] = 1;
    for(ll i = 2; i<N; i++){
        fact[i] = (fact[i-1] * i)%mod;
    }

    int t;
    cin>>t;

    while (t--){
        int n;
        cin>>n;
        
        ll mn = 1e9+1, count = 0, ans;
        vector<ll> v(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
            mn = min(v[i], mn);
        }
        ans = mn;
        for(int i=0; i<n; i++){
            if(v[i] == mn)  count++;
            if((mn&v[i]) != mn){
                count = 1;
                break;
            }
        }

        if(count == 1){
            cout<<0<<endl;
            continue;
        }

        ans = ((count * (count-1))%mod * fact[n-2])%mod;
        cout<<ans<<endl;
    }
    
    
    return 0;
}
