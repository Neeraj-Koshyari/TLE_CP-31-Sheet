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
		int n, l = 0, r = 0;
		cin>>n;

		ll yasser = 0, adel = INT_MIN, sum = 0;

		vector<ll> v(n);
		for(int i=0;i<n;i++){
			cin>>v[i];
			yasser += v[i];

			sum += v[i];
			if(sum > adel){
				adel = sum;
				r = i;
			}

			if(sum <= 0){
				sum = 0;
				l = i;
				r = i;
			}
		}

		if(l == 0 && r == n-1)	adel -= min(v[0],v[n-1]);

		if(yasser > adel)	cout<<"YES\n";
		else cout<<"NO\n";
	}

    return 0;
}
