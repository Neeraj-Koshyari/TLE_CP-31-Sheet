// Problem Link: https://codeforces.com/problemset/problem/1537/E1

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

string find(int i, string& s, int k){
    int len = i;
    string temp = s.substr(0,len);

    while(len < k){
        temp += temp;
        len += len;
    }
    return temp.substr(0,k);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin>>n>>k;

    string s, ans(k,'z');
    cin>>s;

    for(int i=1; i<=n; i++){
        ans = min(ans, find(i, s, k));
    }
    cout<<ans<<endl;
}
