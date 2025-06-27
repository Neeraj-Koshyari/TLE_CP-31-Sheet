// Problem Link: https://codeforces.com/problemset/problem/1195/C

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

    vector<ll> a(n), b(n), sa(n), sb(n);
    for(int i=0; i<n; i++)  cin>>a[i];
    for(int i=0; i<n; i++)  cin>>b[i];

    sa[0] = a[0];
    sb[0] = b[0];
    for(int i=0; i<n-1; i++){
        sa[i+1] = max(sa[i+1], sb[i] + a[i+1]);
        sb[i+1] = max(sb[i+1], sa[i] + b[i+1]);

        if((i+2) < n){
            sa[i+2] = max(sa[i+2], sb[i] + a[i+2]);
            sb[i+2] = max(sb[i+2], sa[i] + b[i+2]);
        }
    }

    cout<<max(sa[n-1], sb[n-1])<<endl;
    
    return 0;
}
