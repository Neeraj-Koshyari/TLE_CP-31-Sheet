// Problem Link: https://codeforces.com/problemset/problem/1886/C

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
        string s;
        cin>>s;

        ll pos;
        cin>>pos;

        pos--;

        ll n = s.length();
        s += '$';

        vector<char> v;
        bool ok = pos < n;

        for(auto& ch : s){
            while(!ok && v.size() > 0 && v.back() > ch){
                pos -= n;
                n--;
                v.pop_back();

                if(pos < n) ok = true;
            }
            v.push_back(ch);
        }
        cout<<v[pos];
    }
    

    return 0;
}
