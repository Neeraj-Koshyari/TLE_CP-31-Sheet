// Problem Link:  https://codeforces.com/problemset/problem/1486/B

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

        vector<int> x_cord(n), y_cord(n);
        for(int i=0; i<n; i++){
            cin>>x_cord[i]>>y_cord[i];
        }

        if(n&1){
                cout<<1<<endl;
                continue;
        }

        sort(x_cord.begin(), x_cord.end());
        sort(y_cord.begin(), y_cord.end());

        ll len1 = x_cord[n/2] - x_cord[n/2 - 1] + 1;
        ll len2 = y_cord[n/2] - y_cord[n/2 - 1] + 1;

        cout<<len1 * 1ll * len2<<endl;
    }

    return 0;
}
