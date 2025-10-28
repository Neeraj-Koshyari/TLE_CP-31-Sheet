// Problem Link: https://codeforces.com/problemset/problem/1458/A

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

    vector<ll> a(n), b(m);
    for(int i=0; i<n; i++)  cin>>a[i];
    for(int i=0; i<m; i++)  cin>>b[i];

    ll g = 0;
    for(int i=1; i<n; i++)  g = gcd(g, a[i]-a[0]);

    for(int i=0; i<m; i++)  cout<<gcd(g, b[i] + a[0])<<" ";
}
