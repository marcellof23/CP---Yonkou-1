#include <bits/stdc++.h>
using namespace std;

char board[3][200];
void print(long long w){
    for(int i=0; i<3; i++){
        for(int j=0; j<w; j++){
            cout << board[i][j];
        }cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    long long w, a, b;
    cin >> w >> a >> b;
    a--; b--;
    for(int i=0; i<3; i++){
        for(int j=0; j<w; j++){
            board[i][j] = '.';
        }
    }
    board[1][0] = 'X';
    board[0][a] = 'A';
    board[2][b] = 'B';
    if(a == b){
        cout << "Possible" << endl;
        print(w);
    }else if(min(a,b) == 0 || (a-b)%2){
        cout << "Impossible" << endl;
    }else if(a-b==2){
        if(b<2){
            cout << "Impossible" << endl;
        }else{
            board[1][b-1] = '*';
            board[2][b-1] = '*';
            cout << "Possible" << endl;
            print(w);
        }
    }else if(b-a==2){
        if(a<2){
            cout << "Impossible" << endl;
        }else{
            board[0][a-1] = '*';
            board[1][a-1] = '*';
            cout << "Possible" << endl;
            print(w);
        }
    }else{
        board[0][a-1] = '*';
        for(int i=min(a,b); i<(a+b)/2; i++){
            board[1][i] = '*';
        }
        board[2][b-1] = '*';
        cout << "Possible" << endl;
        print(w);
    }
}
