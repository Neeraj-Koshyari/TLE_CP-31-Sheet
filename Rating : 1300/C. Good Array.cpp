// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll n, total = 0, mx = 0, prevmx = 0;
	cin>>n;

	vector<ll> v(n),ans;
	for(int i=0;i<n;i++){	
		cin>>v[i];
		total += v[i];
		if(v[i] > mx){
			prevmx = mx;
			mx = v[i];
		}
		else if(v[i] > prevmx && v[i] <= mx)	prevmx = v[i];
	}
	
	total -= mx;

	for(int i=0;i<n;i++){
		if(v[i] == mx){	
			if(total-prevmx == prevmx)	ans.push_back(i+1);
		}
		else if(total - v[i] == mx)	ans.push_back(i+1);
	}

	cout<<ans.size()<<endl;
	for(auto& x:ans)	cout<<x<<" ";
	cout<<endl;

    return 0;
}
