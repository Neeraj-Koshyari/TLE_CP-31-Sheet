// Problem Link: https://codeforces.com/problemset/problem/276/C

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin>>n>>q;

    vector<ll> v(n), count(n+1);
    for(int i=0; i<n; i++)  cin>>v[i];

    sort(v.rbegin(), v.rend());

    while(q--){
        int l,r;
        cin>>l>>r;
        count[l-1]++;
        count[r]--;
    }

    for(int i=1; i<=n; i++)  count[i] += count[i-1];

    sort(count.rbegin(), count.rend());

    ll sum = 0;
    for(int i=0; i<n; i++)  sum += (v[i] * count[i]);
    cout<<sum<<endl;

    return 0;
}
