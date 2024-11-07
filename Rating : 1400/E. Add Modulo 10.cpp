// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin>>t;

	while(t--){
		int n,flag = 0;
		cin>>n;

		ll count = 0;
		vector<ll> v(n);
		
		for(int i=0;i<n;i++){	
			cin>>v[i];
			if(v[i] % 5 == 0)	flag = 1;
			v[i] += v[i] % 10;
		}

		if(flag){
			cout << (*min_element(v.begin(), v.end()) == *max_element(v.begin(), v.end()) ? "Yes": "No") << '\n';
			continue;
		}

		for(int i=0;i<n;i++)	v[i] %= 20;

		sort(v.begin(),v.end());

		for(int i=0; i<n-1; i++){
			while(v[i] < v[n-1]){
				v[i] = v[i] + (v[i]%10);
			}
			if(v[i] != v[n-1]){
				flag = 1;
				break;
			}
		}
		if(flag)	cout<<"No\n";
		else cout<<"Yes\n";
	}

    return 0;
}
