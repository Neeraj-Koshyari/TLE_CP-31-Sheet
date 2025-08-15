// Problem Link: https://codeforces.com/problemset/problem/1404/A?csrf_token=bc2c2cb5f09c73a568411ae8ab0d55f1

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

string find(string& s, int n, int k){
    vector<char> v(k,'?');
    for(int i=0; i<n; i++){
        if(s[i] == '?') continue;

        int idx = i%k;
        if(v[idx] == '?')   v[idx] = s[i];
        else if(v[idx] != s[i]) return "NO";
    }

    int one = 0, zero = 0;
    for(int i=0; i<k; i++){
        if(v[i] == '1') one++;
        else if(v[i] == '0')    zero++;
    }
    
    if(one > k/2 || zero > k/2) return "NO";
    else return "YES";
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
	cin>>t;
	
	while(t--){
        int n,k;
        cin>>n>>k;

        string s;
        cin>>s;

        cout<<find(s,n,k)<<endl;
    }

    return 0;
}
