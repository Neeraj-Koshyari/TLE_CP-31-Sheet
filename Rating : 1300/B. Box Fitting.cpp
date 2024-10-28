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
		ll n,w;
		cin>>n>>w;

		ll height = 0,total = 0;
		vector<int> bits(32);
		for(int i=0;i<n;i++){
			ll x;
			cin>>x;

			total += x;
			bits[log2(x)]++;
		}

		while(total){
			height++;
			ll sum = 0;
			for(int i=31;i>=0;i--){
				ll val = (1ll<<i);
				while(bits[i] && sum+val <= w){
					sum += val;
					bits[i]--;
				}
			}
			total -= sum;
		}
		cout<<height<<endl;
	}
    return 0;
}
