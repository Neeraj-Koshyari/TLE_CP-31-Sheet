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
		ll n;
		cin>>n;

		map<int,int> bits;
		vector<vector<int>> v(n);
		for(int i=0;i<n;i++){
			int sz;
			cin>>sz;
			for(int j=0;j<sz;j++){
				int x;
				cin>>x;
				v[i].push_back(x);
				bits[x]++;
			}
		}

		int flag = 0;
		for(int i=0; i<n;i++){
			flag = 1;
			for(auto& x:v[i]){
				if(bits[x] < 2){
					flag = 0;
					break;
				}
			}
			if(flag)	break;
		}

		if(flag)	cout<<"Yes\n";
		else cout<<"No\n";
	}
    return 0;
}
