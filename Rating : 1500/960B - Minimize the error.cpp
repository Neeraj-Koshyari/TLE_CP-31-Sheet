// Problem Link: https://codeforces.com/problemset/problem/960/B

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k1,k2;
    cin>>n>>k1>>k2;

    vector<ll> diff(n);
    priority_queue<ll> pq;

    for(int i=0; i<n; i++)  cin>>diff[i];
    for(int i=0; i<n; i++){
        ll x;
        cin>>x;

        diff[i] = abs(diff[i] - x);
        pq.push(diff[i]);
    }


    int k = k1+k2;
    while(k){
        ll d = pq.top();
        pq.pop();

        if(d == 0){
            if(k&1) pq.push(1ll);
            else pq.push(0);
            k = 0;
            break;
        }
        d--;
        pq.push(d);
        k--;
    }

    ll sum = 0;
    while(pq.size()){
        ll d = pq.top();
        pq.pop();

        sum += (d*1ll*d);
    }

    cout<<sum<<endl;

    return 0;
}
