// Problem Link: https://codeforces.com/contest/976/problem/C

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool cmp(vector<int>& x, vector<int>& y){
    if(x[0] == y[0])    return x[1] > y[1];
    return x[0] < y[0];
}

void find(vector<vector<int>>& v, int n){
    int l = 0;
    for(int i=1; i<n; i++){
        if(v[i][1] <= v[l][1]){
            cout<<v[i][2]<<" "<<v[l][2]<<endl;
            return;
        }
        else l = i;
    }
    cout<<-1<<" "<<-1<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<vector<int>> v;
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;

        v.push_back({x,y,i+1});
    }

    sort(v.begin(), v.end(), cmp);

    find(v,n);

    return 0;
}
