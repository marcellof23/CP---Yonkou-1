#include <bits/stdc++.h>
using namespace std;

bool vis[100][100][101][101];//
char board[100][100];

queue<int> qx, qy, qs, qb;
void bfs(int expandx, int expandy, int expands, int expandb, int m){
    if(board[expandx][expandy] == '1'){
        if(expands>0 && !vis[expandx][expandy][expands-1][min(m, expandb+1)]){
            vis[expandx][expandy][expands-1][min(m, expandb+1)] = true;
            qx.push(expandx);
            qy.push(expandy);
            qs.push(expands-1);
            qb.push(min(m, expandb+1));
        }
    }else{
        if(expands>0 && !vis[expandx][expandy][expands-1][expandb]){
            vis[expandx][expandy][expands-1][expandb] = true;
            qx.push(expandx);
            qy.push(expandy);
            qs.push(expands-1);
            qb.push(expandb);
        }
    }
    if(expandb>0 && !vis[expandx][expandy][expands][expandb-1]){
        vis[expandx][expandy][expands][expandb-1] = true;
        qx.push(expandx);
        qy.push(expandy);
        qs.push(expands);
        qb.push(expandb-1);
    }
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	long long t;
    cin >> t;
    for(int tt=1; tt<=t; tt++){
        int n, s, b, m;
        cin >> n >> s >> b >> m;
        int sx, sy, tx, ty;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> board[i][j];
                if(board[i][j] == 'S'){
                    sx = i; sy = j;
                }

                if(board[i][j] == 'T'){
                    tx = i; ty = j;
                }
                for(int i1=0; i1<=s; i1++){
                    for(int j1=0; j1<=m; j1++){
                        vis[i][j][i1][j1] = false;
                    }
                }
            }
        }
        while(!qx.empty()){
            qx.pop();qy.pop();qs.pop();qb.pop();
        }
        qx.push(sx);
        qy.push(sy);
        qs.push(s);
        qb.push(b);
        vis[sx][sy][s][b] = true;
        int headx, heady, heads, headb;
        while(!qx.empty()){
            headx = qx.front(); qx.pop();
            heady = qy.front(); qy.pop();
            heads = qs.front(); qs.pop();
            headb = qb.front(); qb.pop();
            if(headx>0 && board[headx-1][heady] != '*'){
                bfs(headx-1, heady, heads, headb, m);
            }
            if(headx<n-1 && board[headx+1][heady] != '*'){
                bfs(headx+1, heady, heads, headb, m);
            }
            if(heady>0 && board[headx][heady-1] != '*'){
                bfs(headx, heady-1, heads, headb, m);
            }
            if(heady<n-1 && board[headx][heady+1] != '*'){
                bfs(headx, heady+1, heads, headb, m);
            }
        }
        string ans = "NO";
        for(int i=0; i<s; i++){
            for(int j=0; j<101; j++){
                if(vis[tx][ty][i][j]){ans = "YES";}
            }
        }
        cout << "Case #" << tt << ": " << ans << endl;
    }
	return 0;
}
