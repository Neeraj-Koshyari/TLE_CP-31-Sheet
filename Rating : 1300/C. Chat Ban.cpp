// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll s1(ll l, ll r, ll val){
	while(l+1<r){
		ll mid = (l+r)/2;

		ll sum = mid*(mid+1)/2;

		if(val >= sum)	l = mid;
		else r = mid;
	}
	return l;
}

ll s2(ll total, ll l, ll r, ll val){
	while(l+1<r){
		ll mid = (l+r)/2;

		ll sum = total - (mid * (mid+1) / 2); 

		if(val > sum) r = mid;
		else l = mid;
	}
	return r;
}

ll sol(){
	ll n,k;
	cin>>k>>n;

	if(k == 1)	return 1;

	ll upper_half = k * (k-1) / 2;
	ll total_emote = 2ll*upper_half + k;
	ll total_lvl = 2ll*k-1;

	if(n <= (upper_half + k)){
		ll lvl = s1(1,k,n);

		if(n > (lvl * (lvl+1) / 2))	return lvl+1;
		else return lvl;
	}
	else{
		n -= upper_half + k;

		ll lvl = total_lvl - s2(upper_half,0,k-1,n) + 1;
		return lvl;
	}

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int t;
	cin>>t;
 
	while(t--){
		cout<<sol()<<endl;
	}
    return 0;
}
