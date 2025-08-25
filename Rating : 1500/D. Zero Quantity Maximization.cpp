// Problem Link: https://codeforces.com/contest/1133/problem/D

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, mx = 0, count = 0;
    cin>>n;

    vector<int> a(n),b(n);
    for(int i=0; i<n; i++)  cin>>a[i];
    for(int j=0; j<n; j++)  cin>>b[j];

    map<pair<int,int>, int> mp;
    for(int i=0; i<n; i++){
        if(a[i] == 0 && b[i] == 0)  count++;
        if(a[i] == 0)  continue;

        int g = gcd(a[i], b[i]);
        int x = a[i]/g;
        int y = -b[i]/g;

        if(a[i] < 0){
            y *= -1;
            x *= -1;
        }

        mp[{y,x}]++;
        mx = max(mx, mp[{y,x}]);
    }
    cout<<mx+count<<endl;

    return 0;
}
