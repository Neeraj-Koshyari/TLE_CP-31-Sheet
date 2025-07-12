// Problem link: https://codeforces.com/problemset/problem/1872/E

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
        ll n, zero = 0, one = 0;
        cin>>n;

        vector<ll> v(n+1);
        for(int i=1; i<=n; i++) cin>>v[i];

        string s;
        cin>>s;

        for(int i=1; i<=n; i++){
            if(s[i-1] == '1') one ^= v[i];
            else zero ^= v[i];

            v[i] ^= v[i-1];
        }

        int q;
        cin>>q;

        while(q--){
            int type;
            cin>>type;

            if(type == 1){
                int l, r;
                cin>>l>>r;

                ll val = v[r] ^ v[l-1];
                one ^= val;
                zero ^= val;
            }
            else{
                int g;
                cin>>g;

                if(g == 0)  cout<<zero<<" ";
                else cout<<one<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}
