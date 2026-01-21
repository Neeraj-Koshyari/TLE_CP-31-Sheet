// Problem Link: https://codeforces.com/problemset/problem/1983/D

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll merge(int l, int mid, int r, vector<int>& v){
    int n = mid-l+1, m = r-mid;
    vector<int> a(n), b(m);

    for(int i=0; i<n; i++) a[i] = v[l+i];
    for(int i=0; i<m; i++)   b[i] = v[mid+1+i];

    ll i = 0, j = 0, k = l, swap = 0;
    while(i<n && j<m){
        if(a[i]>b[j]){
            swap += (n-i);
            v[k] = b[j];
            j++;
        }
        else{
            v[k] = a[i];
            i++;
        }
        k++;
    }

    while(i<n){
        v[k] = a[i];
        i++;
        k++;
    }
    while(j<m){
        v[k] = b[j];
        j++;
        k++;
    }
    return swap;
}

ll find(int l, int r, vector<int>& v){
    if(l<r){
        int mid = (l+r)/2;
        ll val1 = find(l,mid,v);
        ll val2 = find(mid+1,r,v);
        ll val3 = merge(l,mid,r,v);
        return val1+val2+val3;
    }
    return 0;
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
        for(int i=0; i<n; i++)  cin>>a[i];
        for(int i=0; i<n; i++)  cin>>b[i];

        ll x = find(0, n-1, a);
        ll y = find(0, n-1, b);

        if((a==b) && (x%2) == (y%2))  cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}
