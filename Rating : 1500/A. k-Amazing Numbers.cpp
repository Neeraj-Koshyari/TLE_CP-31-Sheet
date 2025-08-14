// Problem Link: https://codeforces.com/problemset/problem/1416/A

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

        vector<vector<int>> v(n+1);
        vector<int> ans(n+1,(int)1e9);
        for(int i=1; i<=n; i++){
            int x;
            cin>>x;
            v[x].push_back(i);
        }

        for(int i=1; i<=n; i++){
            if((int)v[i].size() == 0)  continue;

            int mx = -1, prev = 0;
            for(auto& x:v[i]){
                mx = max(mx,x-prev);
                prev = x;
            }

            mx = max(mx, n+1 - prev);
            ans[mx] = min(ans[mx], i);
        }

        for(int i=1; i<=n; i++){
            ans[i] = min(ans[i], ans[i-1]);
            if(ans[i] == (int)1e9)  cout<<-1<<" ";
            else cout<<ans[i]<<" ";
        }
        cout<<endl;

    }

    return 0;
}
