// Problem Link: https://codeforces.com/problemset/problem/891/A

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, g = 0, flag = 0, one = 0;
    cin>>n;

    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];

        if(v[i] == 1)   one++;

        g = gcd(g, v[i]);
    }

    if(g != 1)  cout<<-1<<endl;
    else if(one)    cout<<n-one<<endl;
    else{
        int count = 0;
        while(flag == 0){
            vector<int> temp(n);
            temp[0] = v[0];
            for(int i=1; i<n; i++){
                temp[i] = gcd(v[i], v[i-1]);
                if(temp[i] == 1){
                    flag = 1;
                    break;
                }
            }
            v = temp;
            count++;
        }
        cout<<count+n-1<<endl;
    }

    return 0;
}
