// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool cmp(pair<int,int>& x, pair<int,int>& y){
	if(x.first == y.first)	return x.second < y.second;
	return x.first > y.first;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin>>t;

	while(t--){
		int n, ans = 0;
		cin>>n;
		
		int x = n, y = n;

		for(int i=0;i<n;i++){
			int val;
			cin>>val;

			if(x > y)	swap(x,y);

			if(val <= x)	x = val;
			else if(val <= y)	y = val;
			else{
				ans++;
				x = val;
			}
		}
		cout<<ans<<endl;
	}

    return 0;
}
