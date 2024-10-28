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
		int n, m = 0;
		cin>>n;

		vector<int> bits(31);
		for(int i=0;i<n;i++){
			int x,idx = 0;
			cin>>x;

			while(x){
				bits[idx] += (x%2);
				idx++;
				m = max(m,idx);
				x/=2;
			}
		}

		cout<<1<<" ";
		for(int i=2;i<=n;i++){
			int flag = 1;
			for(int j=0;j<m;j++){
				if(bits[j] % i != 0){
					flag = 0;
					break;
				}
			}
			if(flag)	cout<<i<<" ";
		}
		cout<<endl;
	}
    return 0;
}
