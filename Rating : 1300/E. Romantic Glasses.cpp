// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include<bits/stdc++.h>
#define ll long long
using namespace std;

void sol(){
	int n,flag = 0;
	cin>>n;

	ll pre = 0;
	set<ll> st;
	st.insert(0);

	for(int i=0; i<n; i++){
		ll x;
		cin>>x;
		if(i&1)	pre -= x;
		else pre += x;
		
		if(st.count(pre))	flag = 1;
		st.insert(pre);
	}

	if(flag)	cout<<"YES\n";
	else	cout<<"NO\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin>>t;
	while(t--){
		sol();
	}
    return 0;
}
