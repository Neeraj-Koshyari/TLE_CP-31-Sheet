// Problem Link: https://codeforces.com/problemset/problem/1332/C

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
        int n,k;
        cin>>n>>k;

        string s;
        cin>>s;

        vector<vector<int>> v(n, vector<int>(26));
        for(int i=0; i<n; i += k){
            for(int j=0; j<(k+1)/2; j++){
                int idx = (s[i+j]-'a');
                v[j][idx]++;
            }
            for(int j=0; j<k/2; j++){
                int idx = (s[i+k-1-j]-'a');
                v[j][idx]++;
            }
        }

        string ans = "";
        for(int i=0; i<(k+1)/2; i++){
            int mx = 0, idx = 0;
            for(int j=0; j<26; j++){
                if(mx < v[i][j]){
                    mx = v[i][j];
                    idx = j;
                }
            }
            ans += ('a'+idx);
        }

        string temp = ans.substr(0,k/2);
        reverse(temp.begin(), temp.end());
        ans += temp;
        
        int count = 0;
        for(int i=0; i<n; i += k){
            for(int j=0; j<k; j++){
                if(s[i+j] != ans[j])    count++;
            }
        }

        cout<<count<<endl;
    }

    return 0;
}
