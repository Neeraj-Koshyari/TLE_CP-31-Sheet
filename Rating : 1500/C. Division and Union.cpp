// Problem Link: https://codeforces.com/problemset/problem/1101/C

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

        vector<vector<int>> v;
        for(int i=0; i<n; i++){
            int x,y;
            cin>>x>>y;

            v.push_back({x,y,i});
        }

        sort(v.begin(), v.end());

        vector<int> ans(n,2);
        int lst = v[0][1], flag = 0;
        ans[v[0][2]] = 1;
        for(int i=1; i<n; i++){
            if(lst < v[i][0]){
                flag = 1;
                break;
            }
            ans[v[i][2]] = 1;
            lst = max(lst,v[i][1]);
        }

        if(!flag)   cout<<-1<<endl;
        else{
            for(int i=0; i<n; i++)  cout<<ans[i]<<" ";
            cout<<endl;
        }
    }

    return 0;
}
