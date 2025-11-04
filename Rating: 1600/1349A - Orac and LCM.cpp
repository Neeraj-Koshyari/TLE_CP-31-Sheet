// Problem Link: https://codeforces.com/problemset/problem/1349/A

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

    vector<ll> v(n);
    for(int i=0; i<n; i++)  cin>>v[i];

    ll g = 0, ans = 0;
    for(int i=n-2; i>=0; i--){
        g = gcd(g, v[i+1]);
        ans = gcd(ans, lcm(v[i], g));
    }
    cout<<ans<<endl;
    return 0;
}
