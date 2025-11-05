// Problem Link: https://codeforces.com/problemset/problem/1389/B

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
        int n,k,z;
        cin>>n>>k>>z;

        vector<ll> v(n), pref(n+1);
        for(int i=0; i<n; i++){
            cin>>v[i];
            pref[i+1] = pref[i] + v[i];
        }

        ll ans = pref[k+1];
        for(int i=1; i<=k; i++){
            ll prevSum = pref[i];
            int remM = min(z, (k+1-i)/2);
            ll currSum = remM * (v[i] + v[i-1]);
            ll nxtSum = max(0ll, pref[k - 2*remM + 1] - pref[i]);

            ans = max(ans, prevSum + currSum + nxtSum);
        }

        cout<<ans<<endl;
    }
    return 0;
}
