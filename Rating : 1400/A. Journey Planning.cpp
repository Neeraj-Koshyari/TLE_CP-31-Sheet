// Problem Link: https://codeforces.com/problemset/problem/1320/A

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, mx = 0;
    cin>>n;

    map<ll,ll> mp;
    for(int i=0; i<n; i++){
        ll val;
        cin>>val;

        mp[i-val] += val;
        mx = max(mx, mp[i-val]);
    }
    cout<<mx<<endl;
    
    return 0;
}
