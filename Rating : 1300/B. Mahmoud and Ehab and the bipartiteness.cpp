// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin>>n;

	vector<ll> zero, one;
	vector<vector<ll>> adj(n+1);

	for(int i=0;i<n-1;i++){
		ll x,y;
		cin>>x>>y;

		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	queue<pair<ll,ll>> qu;
	qu.push({1,-1});
	int clr = 1;

	while(qu.size()){
		clr = 1 - clr;
		int sz = qu.size();
		while(sz--){
			auto pr = qu.front();
			qu.pop();

			int node = pr.first;
			int par = pr.second;

			if(clr == 1)	one.push_back(node);
			else zero.push_back(node);

			for(auto& x:adj[node]){
				if(x == par)	continue;
				qu.push({x,node});
			}
		}
	}
	
	ll x = one.size();
	ll y = zero.size();
	ll ans = x*y - (n-1);
	cout<<ans<<endl;

    return 0;
}
