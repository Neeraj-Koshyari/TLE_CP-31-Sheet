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
		int n,flag = 0,a,b,c;
		cin>>n;

		for(int i=2; i*i<=n; i++){
			if(n%i != 0)	continue;

			int rem = n/i;

			for(int j=2; j*j<=rem; j++){
				if(rem%j != 0 || j == i)	continue;

				int val = rem/j;

				if(val > 1 && val != i && val != j){
					a = i;
					b = j;
					c = n/(i*j);
					flag = 1;
					break;
				}
			}
			if(flag)	break;
		}

		if(flag){
			cout<<"YES\n";
			cout<<a<<" "<<b<<" "<<c<<endl;
		}
		else cout<<"NO\n";
	}

    return 0;
}
