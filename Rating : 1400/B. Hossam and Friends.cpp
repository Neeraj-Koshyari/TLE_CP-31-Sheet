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
		int n,m;
		cin>>n>>m;

		map<int,int> mp;
		for(int i=0;i<m;i++){
			int u,v;
			cin>>u>>v;

			if(u > v)	swap(u,v);
			mp[v] = max(mp[v],u);
		}

		ll start = 1, ans = 0, count = 1;
		for(int i=1;i<=n;i++){
			if(mp[i] >= start){
				start = mp[i]+1;
				count = i - mp[i];
			}
			ans += count;
			count++;
		}
		cout<<ans<<endl;
	}

    return 0;
}
