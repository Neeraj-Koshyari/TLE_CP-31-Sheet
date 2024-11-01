// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k, ans = -1;
	cin>>n>>k;

	vector<int> v(n);

	for(int i=0;i<n;i++) 	cin>>v[i];

	for(int i=0; i<n; i++){
		vector<int> temp = v;
		sort(temp.begin(), temp.begin() + i + 1);

		int total = k;
		for(int j = i; j>=0; j-=2)	total -= temp[j];

		if(total < 0)	break;
		ans = i;
	}

	cout<<ans+1<<endl;
	
    return 0;
}
