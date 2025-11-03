// Problem Link: https://codeforces.com/problemset/problem/1398/C

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

        string s;
        cin>>s;

        vector<ll> p(n+1);
        for(int i=0; i<n; i++)
            p[i+1] = p[i] + (s[i]-'0');
        

        ll count = 0;
        map<ll,ll> mp;
        mp[0] = 1;
        for(int i=1; i<=n; i++){
            count += mp[p[i] - i];
            mp[p[i] - i]++;
        }
        cout<<count<<endl;
    }
    return 0;
}
