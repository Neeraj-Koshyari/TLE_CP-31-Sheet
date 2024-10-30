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
		int n,k,ans = 1;
		cin>>n>>k;

		for(int i=1;i*i<=n && i<=k;i++){
			if(n%i == 0){
				ans = i;
				if(n/i <= k){	
					ans = n/i;
					break;
				}
			}
		}
		cout<<n/ans<<endl;
	}

    return 0;
}
