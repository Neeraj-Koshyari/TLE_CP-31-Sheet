// Problem Link: https://codeforces.com/problemset/problem/1856/C

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool find(ll x, vector<ll>& v, ll k){
    int n = v.size();

    for(int i=0; i<n; i++){
        ll req = 0, curr = x;
        for(int j=i; j<n; j++){
            if(req > k) break;
            if(v[j] >= curr)    return true;

            req += (curr - v[j]);
            curr--;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--){
        ll n,k, mx = 0;
        cin>>n>>k;

        vector<ll> v(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
            mx = max(mx, v[i]);
        }

        ll l = mx, r = mx+n;
        while(l+1 < r){
            ll mid = (l+r)/2;

            if(find(mid, v, k)) l = mid;
            else r = mid;
        }
        cout<<l<<endl;
    }
    

    return 0;
}
