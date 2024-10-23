// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	const int N = 2e5+1, mod = 998244353;;
	vector<int> fact(N);
	fact[0] = fact[1] = 1;

	for(int i=2; i<N; i++)
		fact[i] = (fact[i-1] * 1ll * i)%mod;

	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;

		int n = s.length(), count = 1;
		int mnOpr = 0, ans = 1;

		for(int i=1;i<n;i++){
			if(s[i] != s[i-1]){
				mnOpr += count-1;
				ans = (ans * 1ll * count)%mod;
				count = 1;
			}
			else count++;
		}
		mnOpr += count-1;
		ans = (ans * 1ll * count)%mod;
		ans = (ans * 1ll* fact[mnOpr])%mod;

		cout<<mnOpr<<" "<<ans<<endl;
	}
    return 0;
}
