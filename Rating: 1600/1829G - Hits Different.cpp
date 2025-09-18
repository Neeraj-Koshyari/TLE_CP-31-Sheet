// Problem Link: https://codeforces.com/problemset/problem/1829/G

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll find(ll val){
    return val * (val+1) * (2*val + 1) / 6;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--){
        ll l = 0, r = 2023, n;
        cin>>n;

        while(l+1<r){
            ll mid = (l+r)/2;
            ll val = mid * (mid + 1) / 2;
            
            if(n > val) l = mid;
            else r = mid;
        }

        ll i = r, ans = 0;
        l = n - r * (r-1) / 2;
        r = l;
        
        while(i != 0){
            ll x = i * (i-1) / 2 + r;
            ll y = i * (i-1) / 2 + l - 1;

            ans += (find(x) - find(y));
            l = max(1ll,l-1);
            r = min(r,i-1);
            i--;
        }
        cout<<ans<<endl;
    }
    

    return 0;
}
