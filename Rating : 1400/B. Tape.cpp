// Problem Link: https://codeforces.com/problemset/problem/1110/B

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,k;
    cin>>n>>m>>k;

    int last = 0;
    vector<int> v;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;

        if(i == 0)  last = x;
        else v.push_back(x-last-1);
        last = x;
    }

    sort(v.begin(), v.end());
    int ans = n;
    for(int i=0; i<n-k; i++)    ans += v[i];

    cout<<ans<<endl;
    
    return 0;
}
