// #include<fstream>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int find(string& s){
	int n=s.length(),count=0;
	for(int i=n-1;i>=0;i--){
		if(s[i]!='0')	break;
		count++;
	}
	return count;
}

int main(){
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	
	int t;
	cin>>t;
	while(t--){
		ll n,k,Tlen=0;
		cin>>n>>k;
		vector<ll> diff(n);
		for(int i=0;i<n;i++){
			ll val;
			cin>>val;
			string s = to_string(val);
			
			Tlen += s.length();
			int no_Zero = find(s);
			
			diff[i] = no_Zero;			
		}
		sort(diff.begin(),diff.end(),greater<ll>());
		
		for(int i=0;i<n;i+=2){
			Tlen -= diff[i];
		}
		if(Tlen<=k)	cout<<"Anna"<<endl;
		else cout<<"Sasha"<<endl;
	}
	
	return 0;
}
