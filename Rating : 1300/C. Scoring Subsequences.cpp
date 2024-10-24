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

		vector<int> v(n);

		for(int i=0;i<n;i++){
			cin>>v[i];

			int l = 1, r = i+2;
			while(l+1<r){
				int mid = (l+r)/2;

				if(v[i-mid+1] >= mid)	l = mid;
				else r = mid;
			}
			cout<<l<<" ";
		}
		cout<<endl;
	}
    return 0;
}
