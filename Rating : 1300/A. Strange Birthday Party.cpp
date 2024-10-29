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
		int n,m;
		cin>>n>>m;

		vector<ll> k(n),b(m);
		for(int i=0;i<n;i++)	cin>>k[i];
		for(int i=0;i<m;i++)	cin>>b[i];

		sort(k.rbegin(),k.rend());

		ll j = 0, sum = 0;
		for(int i=0;i<n;i++){
			if(k[i]-1 < j)	sum += b[k[i]-1];
			else{
				sum += b[j];
				j++;
			}
		}
		cout<<sum<<endl;
	}
    return 0;
}
