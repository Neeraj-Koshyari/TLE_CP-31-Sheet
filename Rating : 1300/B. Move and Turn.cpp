// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int n;
	cin>>n;

	int k = n/2;

	if(n&1)	cout<<2*(k+1)*(k+2)<<endl;
	else cout<<(n/2+1)*(n/2+1)<<endl;
    return 0;
}
