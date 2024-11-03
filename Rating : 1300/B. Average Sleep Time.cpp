// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,k;
	cin>>n>>k;

	vector<int> v(n);
	for(int i=0;i<n;i++)	cin>>v[i];

	double ans = 0.0;

	for(int i=1;i<=n;i++){
		double val = min({i,k,n-k+1,n-i+1});
		ans += val*v[i-1];
	}

	

	cout<<fixed<<setprecision(6)<<ans/(double)(n-k+1)<<endl;
    return 0;
}
