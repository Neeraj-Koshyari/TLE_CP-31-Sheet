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

        vector<int> v(n+1), count(n+1,1);
        for(int i=1; i<=n; i++)  cin>>v[i];

        int ans = 1;
        for(int i=1; i<=n; i++){
            for(int j = 2*i; j <= n; j += i){
                if(v[i] < v[j]){
                    count[j] = max(count[j], count[i] + 1);
                    ans = max(ans, count[j]);
                }
            }
        }

        cout<<ans<<endl;
    }
    
    return 0;
}
