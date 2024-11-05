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

		string s;
		cin>>s;

		int mx = 0, mn = 0;
		vector<int> ans(n+1);
		for(int i=0;i<n;i++){
			ans[i+1] = ans[i];
			if(s[i] == '(')	ans[i+1]++;
			else ans[i+1]--;

			mn = min(mn,ans[i+1]);
			mx = max(mx,ans[i+1]);
		}

		if(ans[n] != 0){
			cout<<-1<<endl;
			continue;
		}

		if(mx == 0 || mn == 0){
			cout<<1<<endl;
			for(int i=0;i<n;i++)	cout<<1<<" ";
		}
		else{
			int turn = (s[0] == '(' ? 1 : 2);
			cout<<2<<endl;
			for(int i=1;i<=n;i++){
				cout<<turn<<" ";
				if(ans[i] == 0){
					if(s[i] == '(')	turn = 1;
					else turn = 2;
				}
			}
		}
		cout<<endl;
	}
	
    return 0;
}
