// Problem Link: https://codeforces.com/problemset/problem/1915/F

// Hint: Number of swaps required to sort the array.

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll merge(vector<ll>& v, int l, int mid, int r){
    ll n = mid-l+1, m = r - mid;
    
    vector<ll> left(n), right(m);
    for(int i=0; i<n; i++)  left[i] = v[l + i];
    for(int i=0; i<m; i++)  right[i] = v[mid+1 + i];

    ll i = 0, j = 0, k = l, ans = 0;
    while(i < n && j < m){
        if(left[i] > right[j]){
            ans += n-i;
            v[k] = right[j];
            j++;
        }
        else{
            v[k] = left[i];
            i++;
        }
        k++;
    }

    while(i<n){
        v[k] = left[i];
        i++;
        k++;
    }

    while(j<m){
        v[k] = right[j];
        j++;
        k++;
    }

    return ans;
}

ll find(vector<ll>& b, int l, int r){
    if(l < r){
        int mid = (l+r)/2;

        ll x = find(b, l, mid);
        ll y = find(b, mid+1, r);
        ll z = merge(b, l, mid, r);

        return x + y + z;
    }
    else return 0ll;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--){
        int n, ans = 0;
        cin>>n;

        vector<pair<ll,ll>> v(n);
        for(int i=0; i<n; i++)  cin>>v[i].second>>v[i].first;

        sort(v.begin(), v.end());

        vector<ll> b(n);
        for(int i=0; i<n; i++)  b[i] = v[i].second;

        cout<<find(b, 0 , n-1)<<endl;
    }

    return 0;
}
