// Problem Link: https://codeforces.com/problemset/problem/1167/C

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int find(int x, vector<int>& par){
    if(par[x] == x) return x;
    return par[x] = find(par[x], par);
}

void join(int u, int v, vector<int>& par, vector<int>& count){
    int pu = find(u, par), pv = find(v, par);
    if(pu == pv)    return;

    if(count[pu] < count[pv])   swap(pu, pv);

    count[pu] += count[pv];
    par[pv] = pu;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    vector<int> par(n+1), count(n+1);
    for(int i=0; i<=n; i++){
        par[i] = i;
        count[i] = 1;
    }

    for(int i=0; i<m; i++){
        int sz, first = 0;
        cin>>sz;

        for(int j=0; j<sz; j++){
            int x;
            cin>>x;

            if(j == 0)  first = x;
            else join(first, x, par, count);
        }
    }

    /* Done, find(i,par) insted of par[i] because, as for some cases parent's parent get updated so child parent remain same
    eg:
    7 2
    3-> 1 2 3
    5-> 4 5 6 3 7

    par   => 4 1 1 4 4 4 4
    count => 3 1 1 7 1 1 1

    here parent of 2 and 3 is 1 and number of node in 1 is 3 but parent of 1 is 4 whose size is 7.
    */
    for(int i=1; i<=n; i++) cout<<count[find(i, par)]<<" ";
    
    return 0;
}
