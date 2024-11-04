// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool check(int val , vector<pair<int,int>>& v){
	int l = -val, r = val;

	for(auto& x : v){
		int left = x.first;
		int right = x.second;

		if(r >= left && l <= right){
			l = max(l,left);
			r = min(r,right);

			l -= val;
			r += val;
		}
		else return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		vector<pair<int,int>> v(n);
		for(int i=0;i<n;i++)	cin>>v[i].first>>v[i].second;

		int l = -1, r = 1e9;
		while(l+1 < r){
			int mid = (l+r)/2;

			if(check(mid,v))	r = mid;
			else l = mid;
		}
		cout<<r<<endl;
	}

    return 0;
}
