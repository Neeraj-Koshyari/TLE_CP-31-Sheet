// Problem Link: https://codeforces.com/problemset/problem/1891/C

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
        ll n, left = 0, right = 0;
        cin>>n;

        vector<ll> v(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
            right += v[i];
        }

        sort(v.begin(), v.end());

        ll ans = 0;
        for(int i=0; i<n; i++){
            left += v[i];
            right -= v[i];

            if(left >= right){
                ans += (right + (n-i-1));
                left -= right;
                break;
            }
        }

        if(left == 1)   ans++;
        else if(left > 1) ans += (left+1)/2 + 1;

        cout<<ans<<endl;
    }

    return 0;
}
