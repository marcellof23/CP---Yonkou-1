#include <iostream>

using namespace std;

int t, r1, r2, c1, c2;
bool board[10][35][35];

int main() {
    cin >> t;
    char c;
    while(t--){
        cin >> r1 >> c1;
        //clear
        for(int k=0; k<9; k++){
            for(int i=0; i<30; i++){
                for(int j=0; j<30; j++){
                    board[k][i][j] = false;
                }
            }
        }
        //input
        for(int i=0; i<r1; i++){
            for(int j=0; j<c1; j++){
                cin >> c;
                board[0][i][j] = (c=='#');
                board[1][i][c1-1-j] = (c=='#');
                board[2][r1-1-i][j] = (c=='#');
                board[3][r1-1-i][c1-1-j] = (c=='#');
                board[4][j][i] = (c=='#');
                board[5][c1-1-j][i] = (c=='#');
                board[6][j][r1-1-i] = (c=='#');
                board[7][c1-1-j][r1-1-i] = (c=='#');
            }
        }
        cin >> r2 >> c2;
        for(int i=0; i<r2; i++){
            for(int j=0; j<c2; j++){
                cin >> c;
                board[8][i][j] = (c=='#');
            }
        }
        int ans=0, cur;
        for(int i=-30; i<30; i++){ //offset row
            for(int j=-30; j<30; j++){ //offset col
                for(int k=0; k<8; k++){
                    cur = 0;
                    for(int i2=0; i2<r2; i2++){
                        for(int j2=0; j2<c2; j2++){
                            int i1 = i2+i;
                            int j1 = j2+j;
                            if(0<=i1 && i1<30 && 0<=j1 && j1<30){
                                cur += (board[k][i1][j1] && board[8][i2][j2]);
                            }
                        }
                    }
                    ans = max(ans, cur);
                }
            }
        }
        cout << ans << endl;
    }
}
