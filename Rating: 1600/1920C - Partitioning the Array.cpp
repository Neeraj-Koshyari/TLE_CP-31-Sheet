// Problem Link: https://codeforces.com/problemset/problem/1920/C

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int find(int i, int n, vector<int>& v){
    vector<int> temp(i);
    for(int j=i; j<n; j+=i){
        for(int k=0; k<i; k++)
            temp[k] = gcd(temp[k], abs(v[j+k]-v[j+k-i]));
    }

    int g = 0;
    for(int k=0; k<i; k++)
        g = gcd(g,temp[k]);
    
    return g != 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    
    while (t--){
        int n, count = 0;
        cin>>n;

        vector<int> v(n);
        for(int i=0; i<n; i++)  cin>>v[i];

        for(int i=1; i*i<=n; i++){
            if(n%i != 0)    continue;
            
            count += find(i,n,v);
            if(n/i != i)    count += find(n/i, n, v);
        }

        cout<<count<<endl;
    }
    

    return 0;
}
