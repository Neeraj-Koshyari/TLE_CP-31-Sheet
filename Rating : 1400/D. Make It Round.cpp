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
		ll n, m, k=1;
		cin>>n>>m;

		ll temp = n,cnt2 = 0, cnt5 = 0;
		while(temp > 0 && temp%2 == 0){
			temp/=2;
			cnt2++;
		}
		while(temp > 0 && temp%5 == 0){
			temp/=5;
			cnt5++;
		}
		while(cnt2 < cnt5 && k*2 < m){
			k *= 2;
			cnt2++;
		}
		while(cnt5 < cnt2 && k*5 < m){
			k *= 5;
			cnt5++;
		}
		while(k*10 < m){
			k*=10;
		}
		if(k == 1){
			cout<<n*m<<endl;
		}
		else{
			k *= m/k;
			cout<<n*k<<endl;
		}
	}

    return 0;
}
