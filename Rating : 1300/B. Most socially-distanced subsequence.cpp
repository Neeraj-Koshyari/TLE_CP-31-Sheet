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
		int n,flow = 0,i=1;
		cin>>n;

		vector<int> v(n), ans;
		for(int i=0;i<n;i++)	cin>>v[i];

		ans.push_back(v[0]);
		if(v[1] > v[0])	flow = 1;

		while(i < n){
			if(flow == 1){
				while(i<n && v[i] > v[i-1])	i++;
				ans.push_back(v[i-1]);
				flow = 0;
			}
			else{
				while(i<n && v[i] < v[i-1])	i++;
				ans.push_back(v[i-1]);
				flow = 1;
			}
		}

		cout<<ans.size()<<endl;
		for(auto& x:ans)	cout<<x<<" ";
		cout<<endl;
	}

    return 0;
}
