// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int find(int n){
	for(int i=2;i*i<=n;i++){
		if(n%i == 0)	return i;
	}
	return n;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		int x = find(n);
		cout<<n/x<<" "<<n - n/x<<endl;
	}
    return 0;
}
