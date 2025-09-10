//Problem Link: https://codeforces.com/problemset/problem/1907/E

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

    vector<ll> digsum = {1,3,6,10,15,21,28,36,45,55};
    
    while (t--){
        ll n, count = 1;
        cin>>n;

        while(n){
            count = count * 1ll * digsum[n%10];
            n /= 10;
        }

        cout<<count<<endl;
    }
    

    return 0;
}
