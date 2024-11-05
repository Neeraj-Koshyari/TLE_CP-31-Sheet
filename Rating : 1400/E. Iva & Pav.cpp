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
		int n;
		cin>>n;

		vector<vector<int>> v(n+1,vector<int>(32));
		for(int i=1;i<=n;i++){
			v[i] = v[i-1];
			int x;
			cin>>x;

			int idx = 0;
			while(x){
				if(x&1)	v[i][idx] += 1;
				idx++;
				x /= 2;
			}
		}

		int q;
		cin>>q;
		while(q--){
			int start,k;
			cin>>start>>k;
			start--;

			int l = start, r = n+1;
			while(l+1 < r){
				int mid = (l+r)/2;
				int val = 0, len = mid-start;

				for(int i=0;i<32;i++){
					if(v[mid][i] - v[start][i] >= len)	val += (1<<i);
				}
				
				if(val >= k)	l = mid;
				else r = mid;
			}
			if(l == start)	cout<<-1<<" ";
			else cout<<l<<" ";
		}
		cout<<endl;
	}
	
    return 0;
}
