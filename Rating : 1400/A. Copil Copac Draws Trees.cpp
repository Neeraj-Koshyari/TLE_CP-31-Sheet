// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long
using namespace std;

map<pair<int,int>,int> mp;
int ans;

void find(int node, vector<vector<int>>& adj, int par, int prev){
	for(auto& x: adj[node]){
		if(x == par)	continue;

		if(mp[{node,x}] < mp[{par,node}])	find(x,adj,node,prev+1);
		else find(x,adj,node,prev);
	}
	ans = max(ans,prev);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		vector<vector<int>> adj(n+1);
		
		
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);

			mp[{u,v}] = i;
			mp[{v,u}] = i;
		}

		ans = 1;

		find(1,adj,-1,1);

		cout<<ans<<endl;
	}

    return 0;
}
