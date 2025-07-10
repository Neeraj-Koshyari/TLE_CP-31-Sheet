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
        int n;
        cin>>n;

        vector<ll> v(n);
        for(int i=0; i<n; i++)  cin>>v[i];

        sort(v.begin(), v.end());

        ll ans = 0, x = 0, l = 0, r = n-1;
        while(l<=r){
            if(l == r){
                if(v[r]+x == 1) ans++;
                else ans += ((v[r]+x+1)/2 + 1);
                x = 0;

                break;
            }

            x += v[l];
            if(x >= v[r]){
                ll rem = x - v[r];
                ans += v[r] + 1;

                x = rem;

                r--;
            }
            l++;
        }

        if(x == 1)  ans++;
        else if(x > 1)  ans += (x+1)/2 + 1;
        
        cout<<ans<<endl;
    }

    return 0;
}
