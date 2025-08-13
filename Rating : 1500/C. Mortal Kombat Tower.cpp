// Problem Link: https://codeforces.com/problemset/problem/1418/C

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

        vector<int> v(n);
        for(int i=0; i<n; i++)  cin>>v[i];

        int ans = 0, flag = 0, count = 1;
        for(int i=1; i<n; i++){
            if(v[i] == v[i-1])  count++;
            else{
                if(v[i-1] == 1){
                    if(flag == 0)   ans += (count+2)/3;
                    else ans += (count/3);
                }
                flag = 1;
                count = 1;
            }
        }

        if(v[n-1] == 1){
            if(flag == 0)   ans += (count+2)/3;
            else ans += (count)/3;
        }

        cout<<ans<<endl;
    }

    return 0;
}
