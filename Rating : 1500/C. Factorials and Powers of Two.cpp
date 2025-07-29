// Problem Link: https://codeforces.com/problemset/problem/1646/C

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int countSetBit(ll val){
    int count = 0;
    while(val){
        if(val&1)   count++;
        val /= 2;
    }
    return count;
}

int find(int i, vector<ll>& fact, ll n){
    if(i < 0){
        if(n == 0)  return 1;
        return (int)1e9;
    }

    int take = 1e9;
    if(fact[i] <= n)    take = 1 + min(countSetBit(n-fact[i]), find(i-1, fact, n-fact[i]));
    int not_take = min(countSetBit(n), find(i-1, fact, n));

    return min(take, not_take);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 17;
    vector<ll> fact(N);
    fact[0] = 1;
    
    for(ll i = 1; i<N; i++){
        fact[i] = (fact[i-1] * 1ll * i);
    }

    int t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;

        cout<<find(N-1, fact, n)<<endl;

    }

    return 0;
}
