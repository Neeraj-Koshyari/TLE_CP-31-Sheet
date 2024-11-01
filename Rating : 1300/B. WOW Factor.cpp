// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin>>s;

	ll n = s.length(), count = 1, ans = 0;

	int idx = 0;
	while(idx<n && s[idx] == 'o')	idx++;
	while(idx<n && s[n-1] == 'o')	n--;

	vector<ll> v,o;
	for(int i = idx+1; i<n; i++){
		if(s[i] != s[i-1]){
			if(s[i-1] == 'v')	v.push_back(count - 1);
			else o.push_back(count);

			count = 1;
		}
		else	count++;
	}

	v.push_back(count - 1);

	int m = o.size();
	n = v.size();

	for(int i=n-2;i>=0;i--)	v[i] += v[i+1];

	for(int i=0;i<m;i++)
		ans += (v[0] - v[i+1]) * 1ll * o[i] * 1ll * v[i+1];
	
	cout<<ans<<endl;
	
    return 0;
}
