#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7;
long long t, n, m, C;
bool board[40][40];
char c;

long long fly[2][5][5];

int can[5][5][5][5];

void init(){
    for(int i=0; i<=C; i++){
        for(int j=0; j<=C; j++){
            for(int x=0; x<=C; x++){
                for(int y=0; y<=C; y++){
                    can[i][j][x][y] = 1;
                    if(x==i && x==j && x<C){
                        can[i][j][x][y] = 0;
                    }
                    if(y==i && y==j && y<C){
                        can[i][j][x][y] = 0;
                    }
                    if(i==x && i==y && i<C){
                        can[i][j][x][y] = 0;
                    }
                    if(j==x && j==y && j<C){
                        can[i][j][x][y] = 0;
                    }
                }
            }
        }
    }
}

int main() {
    cin >> t;
    while(t--){
        cin >> n >> m >> C;
        init();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> c;
                board[i][j] = (c=='#');
            }
        }
        for(int k=0; k<m; k++){
            for(int i=0; i<=C; i++){
                for(int j=0; j<=C; j++){
                    fly[k%2][i][j] = 0;
                }
            }
            int lo[2], hi[2];
            for(int i=0; i<2; i++){
                if(board[i][k]){
                    lo[i] = C; hi[i] = C;
                }else{
                    lo[i] = 0; hi[i] = C-1;
                }
            }
            for(int i=lo[0]; i<=hi[0]; i++){
                for(int j=lo[1]; j<=hi[1]; j++){
                    fly[k%2][i][j] = 1;
                }
            }
            /*
            for(int i=0; i<=C; i++){
                for(int j=0; j<=C; j++){
                    cout << fly[k%2][i][j] << ' ';
                }cout << endl;
            }cout << endl;
            */
            if(k>0){
                for(int i=0; i<=C; i++){
                    for(int j=0; j<=C; j++){
                        if(fly[k%2][i][j]){
                            fly[k%2][i][j] = 0;
                            for(int i1=0; i1<=C; i1++){
                                for(int j1=0; j1<=C; j1++){
                                    //cout << can[i][j][i1][j1] << ' ';
                                    fly[k%2][i][j] = (fly[k%2][i][j] + can[i][j][i1][j1]*fly[(k+1)%2][i1][j1])%mod;
                                }
                            }//cout << fly[k%2][i][j] << endl;
                        }
                    }
                }//cout << endl;
            }
        }
        long long ans = 0;
        for(int i=0; i<=C; i++){
            for(int j=0; j<=C; j++){
                ans = (ans + fly[(m+1)%2][i][j])%mod;
            }
        }
        cout << ans << endl;
    }
}
