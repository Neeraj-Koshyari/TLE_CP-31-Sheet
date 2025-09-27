// Problem Link: https://codeforces.com/problemset/problem/1778/C

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<vector<ll>> words;

ll find(string& a, string& b, int idx, int k){
    if(idx < 0 || k == 0){
        ll ans = 0, count = 0, n = a.length();
        for(int i=0; i<n; i++){
            if(a[i] == b[i])    count++;
            else count = 0;

            ans += count;
        }
        return ans;
    }

    ll take = 0;
    if(words[idx].size() != 0){
        for(int x: words[idx])  a[x] = b[x];
        take = find(a, b, idx-1, k-1);
        for(int x: words[idx]) a[x] = 'a'+idx;
    }

    ll not_take = find(a, b, idx-1, k);

    return max(take, not_take);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;

        words = vector<vector<ll>>(26);
        
        string a,b;
        cin>>a>>b;

        for(int i=0; i<n; i++)  words[a[i]-'a'].push_back(i);

        cout<<find(a, b, 25, k)<<endl;
    }
    

    return 0;
}
