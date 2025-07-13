// Problem Link: https://codeforces.com/problemset/problem/1795/C

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
        int n;
        cin>>n;

        vector<ll> a(n+1), b(n+1), pref(n+1);
        for(int i=1; i<=n; i++)  cin>>a[i];
        for(int i=1; i<=n; i++){
            cin>>b[i];
            pref[i] = pref[i-1] + b[i];
        }

        vector<ll> ans(n+2), count(n+2);
        for(int i=1; i<=n; i++){
            int l = i-1, r = n+1;

            while(l+1 < r){
                int mid = (l+r)/2;

                if(a[i] >= (pref[mid] - pref[i-1])) l = mid;
                else r = mid;
            }

            if(r == i)  ans[r] += a[i];
            else    ans[r] += (a[i] - (pref[r-1] - pref[i-1]));
            count[r]++;
        }

        for(int i=1; i<=n; i++){
            count[i] += count[i-1];
            ans[i] += ((i - count[i]) * b[i]);
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        
    }

    return 0;
}
