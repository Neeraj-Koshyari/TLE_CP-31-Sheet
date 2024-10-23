#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;

		vector<int> v(n),p(n,-1);
		cin>>v[0];

		for(int i=1;i<n;i++){
			cin>>v[i];

			p[i] = p[i-1];
			if(v[i] != v[i-1])	p[i] = i-1;
		}

		int q;
		cin>>q;
		while(q--){
			int l,r;
			cin>>l>>r;

			if(l-1 <= p[r-1])	cout<<p[r-1]+1<<" "<<r<<endl;
			else cout<<-1<<" "<<-1<<endl;
		}
		cout<<endl;
	}
    return 0;
}
