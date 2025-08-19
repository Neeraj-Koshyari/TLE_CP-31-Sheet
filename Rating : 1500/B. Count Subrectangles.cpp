// Problem Link: https://codeforces.com/contest/1323/problem/B

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int find(vector<int>& a, vector<int>& b, int n, int m, int x, int y){
    int c1 = 0, c2 = 0, row = 0, col = 0;
    for(int i=0; i<n; i++){
        if(a[i] == 1)   c1++;
        else{
            if(c1 >= x) row += (c1-x+1);
            c1 = 0;
        }
    }
    if(c1 >= x) row += (c1-x+1);

    for(int i=0; i<m; i++){
        if(b[i] == 1)   c2++;
        else{
            if(c2 >= y) col += (c2-y+1);
            c2 = 0;
        }
    }
    if(c2 >= y) col += (c2-y+1);

    return row * col;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,k;
    cin>>n>>m>>k;

    vector<int> a(n), b(m);
    for(int i=0; i<n; i++)  cin>>a[i];
    for(int j=0; j<m; j++)  cin>>b[j];

    ll ans = 0;
    for(int i=1; i*i<=k; i++){
        if(k%i != 0)    continue;
        int x = i, y = k/i;
        ans += find(a,b,n,m,x,y);
        if(x != y)  ans += find(a,b,n,m,y,x);
    }
    cout<<ans<<endl;

    return 0;
}
