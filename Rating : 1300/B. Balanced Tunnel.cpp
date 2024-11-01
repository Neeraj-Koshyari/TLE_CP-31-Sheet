// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	
	int n, ans = 0;
	cin>>n;

	vector<int> a(n), b(n);
	for(int i=0;i<n;i++)	cin>>a[i];
	for(int i=0;i<n;i++)	cin>>b[i];

	set<int> st;
	int i=0,j=0;
	while(j<n){
		if(st.count(a[i])){
			i++;
			continue;
		}
		if(a[i] != b[j]){
			ans++;
			j++;
		}
		else{
			i++;
			j++;
		}
		st.insert(b[j-1]);
	}
	cout<<ans<<endl;

    return 0;
}
