// Problem Link: https://codeforces.com/problemset/problem/1362/C

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
        ll n, ans = 0;
        cin>>n;

        while(n > 1){
            ll r = 1;
            while(r <= n){
                r *= 2ll;
            }
            ans += (r-1);
            n -= (r/2);
        }
        cout<<ans+n<<endl;
    }
    
    return 0;
}
