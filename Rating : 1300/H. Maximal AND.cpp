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
		ll n,k,ans = 0;
		cin>>n>>k;

		vector<int> bits(31);
		for(int i=0;i<n;i++){
			int x, idx = 0;
			cin>>x;

			while(x){
				bits[idx] += x%2;
				x/=2;
				idx++;
			}
		}

		for(int i=30; i>=0; i--){
			if(n-bits[i] <= k){
				k -= (n-bits[i]);
				bits[i] = n;
			}
		}

		for(int i=0;i<31;i++){
			if(bits[i] == n)	ans += (1ll<<i);
		}
		cout<<ans<<endl;
		
	}
    return 0;
}
