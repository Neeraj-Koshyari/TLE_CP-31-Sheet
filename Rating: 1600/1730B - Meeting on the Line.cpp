// Problem Link: https://codeforces.com/problemset/problem/1730/B

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
        cout<<fixed<<setprecision(7);

        vector<vector<double>> v(n,vector<double>(2));
        for(int i=0; i<n; i++)  cin>>v[i][0];
        for(int i=0; i<n; i++)  cin>>v[i][1];

        sort(v.begin(), v.end());

        double l = v[0][0]-1, r = v[n-1][0]+1;
        for(int i=0; i<50; i++){
            double mid = (l+r)/2.0;

            double left = 0, right = 0;
            for(auto& x:v){
                double val = x[0], time = x[1];
                
                if(val < mid)  left = max(left, mid-val+time);
                else if(val > mid) right = max(right, val-mid+time);
            }

            if(left >= right)   r = mid;
            else l = mid;
        }
        cout<<r<<endl;
    }
}
