// Problem Link: https://codeforces.com/problemset/problem/1407/C

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

    if(n == 1){
        cout<<"! "<<1<<endl;
        return 0;
    }

    vector<int> ans(n,-1);
    queue<int> qu;

    for(int i=1; i<=n; i++) qu.push(i);

    while(qu.size() > 1){
        int idx1 = qu.front();
        qu.pop();

        int idx2 = qu.front();
        qu.pop();

        int a, b;
        cout<<"? "<<idx1<<" "<<idx2<<endl;
        cin>>a;

        cout<<"? "<<idx2<<" "<<idx1<<endl;
        cin>>b;

        if(a > b){
            ans[idx1-1] = a;
            qu.push(idx2);
        }
        else{
            ans[idx2-1] = b;
            qu.push(idx1);
        }
    }

    ans[qu.front()-1] = n;
    cout<<"! ";
    for(auto& x: ans)   cout<<x<<" ";
    cout.flush();
    return 0;
}
