// Problem Link: https://codeforces.com/problemset/problem/1201/B

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    ll total = 0, mx = 0, x;
    for(int i=0; i<n; i++){
        cin>>x;
        total += x;
        mx = max(mx, x);
    }

    if(total&1 || (total-mx) < mx) cout<<"NO\n";
    else cout<<"YES\n";

    return 0;
}
