// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	cin>>s;

	int n = s.length();

	for(int i=1;i<n;i++){
		if(s[i] == s[i-1]){
			if(i != n-1){
				if(s[i] == 'a'){	
					if(s[i+1] == 'b')	s[i] = 'c';
					else s[i] = 'b';
				}
				else{
					if(s[i+1] == 'a')	s[i] = (s[i] == 'b')? 'c' : 'b';
					else	s[i] = 'a';
				}
			}
			else	s[i] = (s[i] == 'a')? 'b':'a';
		}
	}
	cout<<s<<endl;

    return 0;
}
