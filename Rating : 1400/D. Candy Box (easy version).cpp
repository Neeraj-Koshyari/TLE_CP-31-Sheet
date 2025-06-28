// Problem Link: https://codeforces.com/problemset/problem/1183/D

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

        vector<int> v(n);
        for(int i=0; i<n; i++){
            int x;
            cin>>x;

            v[x-1]++;
        }

        sort(v.rbegin(), v.rend());

        ll ans = v[0], prev = v[0];
        for(int i=1; i<n; i++){
            if(prev == 0)   break;
            
            if(v[i] >= prev){
                ans += (prev-1);
                prev = prev-1;
            }
            else if(v[i] < prev){
                ans += v[i];
                prev = v[i];
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}
