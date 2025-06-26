// Problem Link: https://codeforces.com/problemset/problem/1215/B

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    ll po = 0, ne = 0, a = 0, b = 0;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;

        if(x < 0){
            swap(a,b);
            b++;
        }
        else a++;

        po += a;
        ne += b;
    }

    cout<<ne<<" "<<po<<endl;
    
    return 0;
}
