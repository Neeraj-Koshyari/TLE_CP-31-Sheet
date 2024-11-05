// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool check(int x, vector<int>& a, vector<int>& b){
	int n = a.size();

	for(int i = x; i<n; i++){
		if(a[i-x] >= b[i])	return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin>>t;

	while(t--){
		int n,m;
		cin>>n>>m;

		vector<int> a(n,1),b(n);
		for(int i=1;i<n;i++)	cin>>a[i];
		for(int j=0;j<n;j++)	cin>>b[j];

		sort(a.begin(),a.end());
		sort(b.begin(),b.end());

		int l = -1, r = n;
		while(l+1<r){
			int mid = (l+r)/2;

			if(check(mid,a,b))	r = mid;
			else l = mid;
		}

		cout<<r<<endl;
	}
	
    return 0;
}
