// Problem Link: https://codeforces.com/problemset/problem/1475/C

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
        int a,b,k;
        cin>>a>>b>>k;

        vector<int> boys(k), girls(k), A(a), B(b);
        for(int i=0; i<k; i++){  
            cin>>boys[i];
            boys[i]--;

            A[boys[i]]++;
        }
        for(int i=0; i<k; i++){
            cin>>girls[i];
            girls[i]--;

            B[girls[i]]++;
        }

        ll ans = 0;
        for(int i=0; i<k; i++)  
            ans += (k-A[boys[i]]-B[girls[i]]+1);

        cout<<ans/2<<endl;
        
    }
    
    return 0;
}
