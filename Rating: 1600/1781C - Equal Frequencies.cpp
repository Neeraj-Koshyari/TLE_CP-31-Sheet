// Problem Link: https://codeforces.com/problemset/problem/1781/C

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

        string s;
        cin>>s;

        vector<vector<int>> at(26);
        for (int i = 0; i < n; i++) 
            at[(int) (s[i] - 'a')].push_back(i);

        vector<int> order(26);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int i, int j){
            return at[i].size() > at[j].size();
        });

        string res = "";
        int best = -1, freq = -1;
        for (int cnt = 1; cnt <= 26; cnt++) {
            if (n % cnt == 0) {
                int cur = 0;
                for (int i = 0; i < cnt; i++) 
                    cur += min(n / cnt, (int) at[order[i]].size());
                
                if (cur > best){
                    best = cur;
                    freq = cnt;
                }
            }
        }

        int cnt = freq;
        res = string(n, ' ');
        vector<char> extra;
        for (int it = 0; it < cnt; it++) {
            int i = order[it];
            for (int j = 0; j < n / cnt; j++) {
                if (j < (int) at[i].size())
                    res[at[i][j]] = (char) ('a' + i);
                else
                    extra.push_back((char) ('a' + i));
            }
        }
        for (char& c : res) {
            if (c == ' ') {
                c = extra.back();
                extra.pop_back();
            }
        }

        cout<<n-best<<endl;
        cout<<res<<endl;
    }
    return 0;
}
