// Problem Link: https://codeforces.com/problemset/problem/1659/C

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--){
        ll n, a, b, total = 0;
        cin>>n>>a>>b;

        vector<ll> v(n+1);
        for(int i=1; i<=n; i++){
            cin>>v[i];
            total += v[i];
        }

        ll sum = 0, ans = 1e18+1;
        for(int i=0; i<=n; i++){
            sum += v[i];
            ans = min(ans, (b * v[i]) + (a * v[i]) + b*( total - sum - (n - i) * v[i]));
        }
        cout<<ans<<endl;
    }

    return 0;
}
