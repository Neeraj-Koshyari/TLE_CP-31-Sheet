// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool check(ll x, vector<ll>& v){
	ll val = 0, n = v.size();
	for(int i=0;i<n;i++){
		if(v[i] >= x){
			val += (v[i]-x)*2ll;
		}
		else{
			ll rem = x - v[i];
			if(rem&1)	rem--;
			val -= rem;
		}
		if(val <= 0)	return true;
	}
	return false;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin>>t;

	while(t--){
		int n,m;
		cin>>n>>m;

		vector<ll> v(n);
		for(int i=0;i<m;i++){
			int x;
			cin>>x;
			v[x-1]++;
		}

		sort(v.begin(),v.end(),greater<int>());

		ll l = 0, r = m;
		while (l+1<r){
			ll mid = (l+r)/2;
			if(check(mid,v))	r = mid;
			else l = mid;
		}
		cout<<r<<endl;
	}

    return 0;
}
