// Problem Link: https://codeforces.com/problemset/problem/1776/L

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    string s;
    cin>>s;

    ll t1 = 0, t2 = 0;
    for(int i=0; i<n; i++){
        if(s[i] == '+') t1++;
        else t2++;
    }

    int q;
    cin>>q;
    while(q--){
        ll a,b;
        cin>>a>>b;
        
        ll x = (t2 - t1) * b;
        ll y = (a-b);


        if(y == 0){
            if(t1 == t2)  cout<<"YES\n";
            else cout<<"NO\n";
        }
        else if(x%y == 0){
            if((x/y) <= t1 && (x/y) >= (-1 * t2)) cout<<"YES\n";
            else cout<<"NO\n";
        }
        else cout<<"NO\n";
    }

    return 0;
}
