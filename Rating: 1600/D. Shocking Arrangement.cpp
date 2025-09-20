// Problem Link: https://codeforces.com/problemset/problem/1798/D

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

        vector<ll> pos, neg, ans;
        for(int i=0; i<n; i++){
            ll x;
            cin>>x;

            if(x<0) neg.push_back(x);
            else if(x > 0)  pos.push_back(x);
        }

        if(pos.size() == 0 && neg.size() == 0){
            cout<<"No\n";
            continue;
        }

        sort(pos.begin(), pos.end());
        sort(neg.rbegin(), neg.rend());

        ll mx = pos.back(), mn = neg.back(), sum = 0;
        int i=pos.size() - 1, j = neg.size() - 1;

        while(i >= 0 || j >= 0){
            while(i >= 0 && sum+pos[i] > mn && sum + pos[i] <= mx){
                sum += pos[i];
                ans.push_back(pos[i]);
                i--;
            }
            while(j>=0 && sum + neg[j] > mn && sum + neg[j] <= mx){
                sum += neg[j];
                ans.push_back(neg[j]);
                j--;
            }
        }

        cout<<"Yes\n";
        while(ans.size() != n)  ans.push_back(0);
        for(int x:ans)  cout<<x<<" ";
        cout<<endl;
    }
    

    return 0;
}
