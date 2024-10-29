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
		int n,x,m;
		cin>>n>>x>>m;

		int l = x, r = x;
		while(m--){
			int a,b;
			cin>>a>>b;

			if(l>=a && l<=b || r>=a && r<=b){
				l = min(l,a);
				r = max(r,b);
			}
		}
		cout<<(r-l+1)<<endl;
	}

    return 0;
}
