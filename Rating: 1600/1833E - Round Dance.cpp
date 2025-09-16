// Problem Link: https://codeforces.com/problemset/problem/1833/E

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
        
        vector<int> v(n+1), par(n+1, -1);
        for(int i=1; i<=n; i++) cin>>v[i];

        int mn = 0, mx = 0;

        for(int i=1; i<=n; i++){
            int curr = i;
            while(par[curr] == -1){
                par[curr] = i;
                curr = v[curr];
            }

            int nxt = v[curr];
            if(par[curr] == i){
                if(curr != v[nxt])   mn++;
                mx++;
            }
        }
        cout<<min(mn+1,mx)<<" "<<mx<<endl;
    }
    

    return 0;
}
