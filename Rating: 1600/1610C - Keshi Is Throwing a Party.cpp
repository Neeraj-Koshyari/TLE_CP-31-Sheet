// Problem Link: https://codeforces.com/problemset/problem/1610/C

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool ok(int x, vector<int>& a, vector<int>& b, int n){
    int count = 0;
    for(int i=n-1; i>=0; i--){
        if(a[i] >= count && b[i] >= x-count)    count++;
    }
    return count > x;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> a(n), b(n);
        for(int i=0; i<n; i++)  cin>>a[i]>>b[i];

        int l = -1, r = n;
        while(l+1 < r){
            int mid = (l+r)/2;

            if(ok(mid, a, b, n))    l = mid;
            else r = mid;
        }
        cout<<r<<endl;
    }
}
