// Problem Link: https://codeforces.com/problemset/problem/1374/D

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
        ll n,k;
        cin>>n>>k;

        map<ll,int> mp;
        vector<ll> v(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
            
            ll temp =  (k - (v[i] % k)) % k;

            if(temp == 0){
                v[i] = 0;
                continue;
            }

            v[i] = k * 1ll * mp[temp] + temp;

            mp[temp]++;
        }

        ll ans = 0, x = 0;
        sort(v.begin(),v.end());

        for(int i=0; i<n; i++){
            if(v[i] == 0)   continue;

            v[i] %= k;

            if(v[i] == x)   ans++;
            else if(v[i] > x)   ans += (v[i] - x + 1);
            else    ans += (k - x + v[i] + 1);
            
            x = (v[i] + 1)%k;
        }
        cout<<ans<<endl;
    }
    
    return 0;
}
