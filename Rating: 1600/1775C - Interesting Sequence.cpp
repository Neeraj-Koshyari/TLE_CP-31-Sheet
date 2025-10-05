// Problem Link: https://codeforces.com/problemset/problem/1775/C

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
        ll n, k, flag = 1, f1 = 0, ans = 0;
        cin>>n>>k;
        
        for(int idx = 62; idx >= 0; idx--){
            if(!(k&(1ll<<idx)) && !(n & (1ll<<idx)))    continue;

            if((k & (1ll<<idx))){
                if(f1 == 1 || !(n & (1ll<<idx))){
                    flag = 0;
                    break;
                }
                ans += (1ll<<idx);
            }
            else if(f1 == 0){
                if((n & (1ll<<(idx+1))))    flag = 0;
                else ans += (1ll<<(idx+1));
                f1 = 1;
            }
        }

        if(flag)    cout<<ans<<endl;
        else cout<<-1<<endl;

    }
}
