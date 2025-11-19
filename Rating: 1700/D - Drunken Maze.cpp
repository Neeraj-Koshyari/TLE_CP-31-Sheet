// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class A {
public:
    int step, direction, dstep, x, y;

    A(int step, int direction, int dstep, int x, int y){
        this->step = step;
        this->direction = direction;
        this->dstep = dstep;
        this->x = x;
        this->y = y;
    }
    
    bool operator<(const A& o) const {
        if(step != o.step) return step < o.step;
        if(x != o.x) return x < o.x;
        if(y != o.y) return y < o.y;
        if(direction != o.direction) return direction < o.direction;
        return dstep < o.dstep;
    }

};

bool notOk(int x, int y, int n, int m){
    if(x<0 || y<0 || x>=n || y>=m)  return true;
    return false;
}

int find(vector<string>& v, int sx, int sy, int ex, int ey, int n, int m){
    int ax[] = {1, -1, 0, 0};
    int ay[] = {0, 0, 1, -1};
    int dir[] = {1, 2, 3, 4};
    int oppDir[] = {2, 1, 4, 3};

    set<A> st;
    st.insert(A(0, 0, 0, sx, sy));

    while(st.size()){
        A node = *st.begin();
        st.erase(st.begin());

        if(node.x == ex && node.y == ey)    return node.step;
        v[node.x][node.y] = '#';

        for(int i=0; i<4; i++){
            int nx = node.x + ax[i], ny = node.y + ay[i];

            if(notOk(nx, ny, n, m) || v[nx][ny] == '#') continue;

            if(node.dstep == 3 && node.direction == dir[i]){
                st.insert(A(node.step+1, oppDir[dir[i]-1], 1, node.x - ax[i], node.y - ay[i]));
                v[node.x][node.y] = '.';
            }
            else if(node.direction == dir[i])
                st.insert(A(node.step+1, dir[i], node.dstep+1, nx, ny));
            else
                st.insert(A(node.step+1, dir[i], 1, nx, ny));
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m, sx,sy, ex,ey;;
    cin>>n>>m;

    vector<string> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
        for(int j=0; j<m; j++){
            if(v[i][j] == 'S'){
                sx = i;
                sy = j;
                v[i][j] = '.';
            }
            else if(v[i][j] == 'T'){
                ex = i;
                ey = j;
                v[i][j] = '.';
            }
        }
    }

    cout<<find(v, sx, sy, ex, ey, n, m);

    return 0;
}
