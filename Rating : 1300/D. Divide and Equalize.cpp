// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include<bits/stdc++.h>
#define ll long long
using namespace std;

void find(int x, map<int,int>& mp){
	for(int i=2; i*i <= x; i++){
		while(x%i == 0){
			x/=i;
			mp[i]++;
		}
	}
	if(x > 1)	mp[x]++;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin>>t;
	while(t--){
		int n,flag = 1;
		cin>>n;

		map<int,int> mp;

		for(int i=0;i<n;i++){
			int x;
			cin>>x;

			find(x,mp);
		}

		for(auto& x:mp){
			if(x.second%n){
				flag = 0;
				break;
			}
		}
		if(flag)	cout<<"YES\n";
		else cout<<"NO\n";
	}
    return 0;
}
