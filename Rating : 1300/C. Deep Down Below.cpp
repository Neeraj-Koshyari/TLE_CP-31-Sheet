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
		int n;
		cin>>n;
		
		vector<pair<ll,ll>> v(n);
		for(int i=0;i<n;i++){
			ll m, mx = 0;
			cin>>m;
			
			vector<ll> temp(m);
			for(int j=0;j<m;j++){
				ll x;
				cin>>x;

				mx = max(mx,x-j);
			}

			v[i] = {mx,m};
		}

		sort(v.begin(),v.end());

		ll ans = 0, count = 0;

		for(int i=0; i<n; i++){
			ans = max(ans,v[i].first - count);
			count += v[i].second;
		}
		cout<<ans+1<<endl;
	}
    return 0;
}
