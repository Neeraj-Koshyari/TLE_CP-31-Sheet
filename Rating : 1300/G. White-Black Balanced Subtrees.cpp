// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int ans;

int find(int node, vector<vector<int>>& adj, string& s){
	int val = 0;

	for(auto& x:adj[node]){
		val += find(x,adj,s);
	}

	if(s[node-1] == 'W')	val++;
	else val--;

	if(val == 0)	ans++;

	return val;
	
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int t;
	cin>>t;
 
	while(t--){
		int n;
		cin>>n;
		ans = 0;

		vector<vector<int>> adj(n+1);
		for(int i=2;i<=n;i++){
			int x;
			cin>>x;
			adj[x].push_back(i);
		}

		string s;
		cin>>s;
		
		find(1,adj,s);
		cout<<ans<<endl;
	}
    return 0;
}
