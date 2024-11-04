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
		int n,k;
		cin>>n>>k;

		vector<ll> v(n);
		for(int i=0;i<n;i++)	cin>>v[i];

		if(k > 2){
			cout<<0<<endl;
			continue;
		}

		sort(v.begin(),v.end());
		ll mn = v[0], mn2 = v[0];
		for(int i=0;i<n;i++){

			for(int j=i+1;j<n;j++){
				ll diff = v[j] - v[i];

				mn = min(mn,diff);

				int idx = upper_bound(v.begin(),v.end(),diff) - v.begin();
				if(idx != n)	mn2 = min(mn2, v[idx] - diff);
				if(idx != 0)	mn2 = min(mn2, diff - v[idx-1]);
			}
		}

		if(k == 2)	mn = min(mn, mn2);
		cout<<mn<<endl;
	}

    return 0;
}
