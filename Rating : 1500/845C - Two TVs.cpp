// Problem Link: https://codeforces.com/problemset/problem/845/C

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
    
    vector<pair<int,int>> v(n);
    for(int i=0; i<n; i++)  cin>>v[i].first>>v[i].second;

    sort(v.begin(), v.end());

    int tv1 = 0, tv2 = 1, flag = 1;
    for(int i = 2; i<n; i++){
        if(v[i].first > v[tv1].second)  tv1 = i;
        else if(v[i].first > v[tv2].second) tv2 = i;
        else{
            flag = 0;
            break;
        }
    }

    if(flag)    cout<<"YES\n";
    else cout<<"NO\n";

    return 0;
}
