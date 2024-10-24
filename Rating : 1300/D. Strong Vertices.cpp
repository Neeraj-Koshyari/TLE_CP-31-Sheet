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
		ll n,mx = -3e9,count = 0;
		cin>>n;

		vector<ll> v(n);
		for(int i=0;i<n;i++)	cin>>v[i];

		for(int i=0;i<n;i++){
			ll x;
			cin>>x;
			v[i]-=x;
			mx = max(mx,v[i]);
		}

		for(int i=0;i<n;i++){
			if(mx == v[i])	count++;
		}

		cout<<count<<endl;
		for(int i=0;i<n;i++){
			if(mx == v[i])	cout<<i+1<<" ";
		}
		cout<<endl;
	}
    return 0;
}
