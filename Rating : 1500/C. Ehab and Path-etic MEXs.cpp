// Problem Link: https://codeforces.com/contest/1325/problem/C

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
    
    vector<vector<int>> adj(n+1), edges;
    for(int i=1; i<n; i++){
        int u,v;
        cin>>u>>v;

        edges.push_back({u,v});
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int flag = 0;
    set<vector<int>> st;
    for(int i=1; i<=n; i++){
        if((int)adj[i].size() >= 3){
            int count = 0;
            for(auto &x:adj[i]){
                st.insert({i,x});
                st.insert({x,i});
                count++;

                flag = 1;
                if(count == 3)  break;
            }
        }
        if(flag)    break;
    }

    if(flag == 0){
        for(int i=1; i<n; i++)  cout<<i-1<<endl;
    }
    else{
        int c1 = 0, c2 = 3;
        for(auto& x:edges){
            if(st.count(x)){
                cout<<c1<<endl;
                c1++;
            }
            else{
                cout<<c2<<endl;
                c2++;
            }
        }
    }

    return 0;
}
