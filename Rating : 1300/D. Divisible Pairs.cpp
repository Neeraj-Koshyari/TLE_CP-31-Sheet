// Problem Link : https://codeforces.com/problemset/problem/1931/D

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){	
	int t;
	cin>>t;
	while(t--){
		ll n,x,y,count=0;
		cin>>n>>x>>y;
		
		map<pair<ll,ll>,ll> mp;
		for(int i=0;i<n;i++){	
			ll val;
			cin>>val;
			count += mp[{(x-(val%x))%x,val%y}];
			mp[{val%x,val%y}]++;
		}
		cout<<count<<endl;
	}
	
	return 0;
}
