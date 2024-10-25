// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int t;
	cin>>t;
 
	while(t--){
		ll ans = 0, n;
		cin>>n;

		vector<int> v;
		for(int i=1; i<=n; i++){
			int x;
			cin>>x;

			if(x >= i)	continue;

			ans += (ll)(lower_bound(v.begin(),v.end(),x) - v.begin());
			v.push_back(i);
		}

		cout<<ans<<endl;
	}
    return 0;
}
