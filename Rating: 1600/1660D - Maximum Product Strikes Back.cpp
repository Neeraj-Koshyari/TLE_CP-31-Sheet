// Problem Link: https://codeforces.com/problemset/problem/1660/D

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

        vector<ll> v(n+2);
        for(int i=1; i<=n; i++)  cin>>v[i];

        ll mx = 0, l = 1, r = 0;
        for(int i=1; i<=n+1; i++){
            ll idx = i,fn = -1,ln = -1, count = 0;

            while(v[idx] != 0){
                if(v[idx] < 0){
                    if(fn == -1){
                        fn = idx;
                        ln = idx;
                    }
                    else    ln = idx;

                    count++;
                }
                idx++;
            }

            ll val = 0, left, right;
            if(count&1){
                ll mx1 = 0, mx2 = 0;
                for(int j=fn+1; j<idx; j++){
                    if(abs(v[j]) == 2)  mx1++;
                }
                for(int j=i; j<ln; j++){ 
                    if(abs(v[j]) == 2) mx2++;
                }

                if(mx1 > mx2){
                    val = mx1;
                    left = fn+1;
                    right = idx-1;
                }
                else{
                    val = mx2;
                    left = i;
                    right = ln-1;
                }
            }
            else{
                for(int j=i; j<idx; j++){
                    if(abs(v[j]) == 2)  val++;
                }
                left = i;
                right = idx-1;
            }

            if(mx <= val){
                mx = val;
                l = left;
                r = right;
            }

            i = idx;
        }
        cout<<l-1<<" "<<n-r<<endl;
    }
}
