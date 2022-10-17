#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define pipi pair<int, pii>

const long long maxn = 2048;
int n, m, lt, rt, r, c, d;
int dis[maxn][maxn][2], ans = 0;
pii tempii;
pipi tempipi;
set<pipi> s;
string board[maxn];


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> r >> c >> lt >> rt;
	r--; c--;
	for(int i=0; i<n; i++){
        cin >> board[i];
        for(int j=0; j<m; j++){
            dis[i][j][0] = 1e9;
            dis[i][j][1] = 1e9;
        }
	}
	dis[r][c][0] = 0;
	dis[r][c][1] = 0;
	s.insert({0, {r, c}});
	while(!(s.empty())){
        d = s.begin()->first;
        r = (s.begin()->second).first;
        c = (s.begin()->second).second;
        board[r][c] = '*';
        s.erase({d, {r, c}});
        ans++;
        if(r>0 && board[r-1][c] == '.' && d < dis[r-1][c][0] + dis[r-1][c][1]){
            s.erase({dis[r-1][c][0] + dis[r-1][c][1], {r-1, c}});
            dis[r-1][c][0] = dis[r][c][0];
            dis[r-1][c][1] = dis[r][c][1];
            s.insert({d, {r-1, c}});
        }
        if(r<n-1 && board[r+1][c] == '.' && d < dis[r+1][c][0] + dis[r+1][c][1]){
            s.erase({dis[r+1][c][0] + dis[r+1][c][1], {r+1, c}});
            dis[r+1][c][0] = dis[r][c][0];
            dis[r+1][c][1] = dis[r][c][1];
            s.insert({d, {r+1, c}});
        }
        if(c>0 && board[r][c-1] == '.' && d+1 < dis[r][c-1][0] + dis[r][c-1][1]){
            if(dis[r][c][0] < lt){
                s.erase({dis[r][c-1][0] + dis[r][c-1][1], {r, c-1}});
                dis[r][c-1][0] = dis[r][c][0]+1;
                dis[r][c-1][1] = dis[r][c][1];
                s.insert({d+1, {r, c-1}});
            }
        }
        //cout << r << " " << c << " " << dis[r][c][0] << " " << dis[r][c][1] << endl;
        if(c<m-1 && board[r][c+1] == '.' && d+1 < dis[r][c+1][0] + dis[r][c+1][1]){
            //cout << "masuk " << dis[r][c][1] << " " << rt << endl;
            if(dis[r][c][1] < rt){
                s.erase({dis[r][c+1][0] + dis[r][c+1][1], {r, c+1}});
                dis[r][c+1][0] = dis[r][c][0];
                dis[r][c+1][1] = dis[r][c][1]+1;
                s.insert({d+1, {r, c+1}});
            }
        }
	}
	cout << ans << endl;
	return 0;
	for(int i=0; i<n; i++){
        cout << board[i] << endl;
	}
}
