// Problem Link: https://codeforces.com/problemset/problem/1338/A

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

        vector<ll> v(n);
        for(int i=0; i<n; i++)  cin>>v[i];

        ll mxDiff = 0, mx = v[0];
        for(int i=1; i<n; i++){
            if(v[i] >= mx)  mx = max(mx, v[i]);
            else mxDiff = max(mxDiff, mx - v[i]);
        }

        ll time = 0;
        while(mxDiff){
            time++;
            mxDiff /= 2;
        }

        cout<<time<<endl;
    }

    return 0;
}
