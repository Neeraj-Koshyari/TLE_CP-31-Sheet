// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	const ll N = 1e6;
	set<ll> ans;

	for(ll k=2; k<N; k++){
		ll val = 1 + k + k*k, p = k*k;
		while(val < N){
			ans.insert(val);
			p *= k;
			val += p;
		}
	}

	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		if(ans.count(n))	cout<<"YES\n";
		else cout<<"NO\n";
	}
    return 0;
}
