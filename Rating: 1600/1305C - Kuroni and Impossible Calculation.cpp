// Problem Link: https://codeforces.com/problemset/problem/1305/C

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    vector<ll> v(n);
    for(int i=0; i<n; i++)  cin>>v[i];

    if(n > m){
        cout<<0<<endl;
        return 0;
    }

    ll ans = 1;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            ans = (ans * abs(v[i] - v[j]))%m;
        }
    }
    cout<<ans<<endl;
    return 0;
}
