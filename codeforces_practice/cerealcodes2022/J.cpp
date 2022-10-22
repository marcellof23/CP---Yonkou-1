#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7, maxn=1024;
long long n, board[maxn][maxn], cur=0;
char c;
long long nxt[maxn*maxn], zeros;
long long pangkat[maxn*maxn], ans = 1;
bool vis[maxn*maxn];

void print(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> c;
            if(c == '#'){
                cur++; board[i][j] = cur;
            }else{
                board[i][j] = 0;
            }
        }
	}
	//print();
	// Geser kanan
	for(int i=0; i<n; i++){
        for(zeros = n-1; zeros>=0 && board[i][zeros] == 0; zeros--){}
        for(int j=n-1; j>=n-1-zeros; j--){
            board[i][j] = board[i][j-n+1+zeros];
        }
        for(int j=n-2-zeros; j>=0; j--){
            board[i][j] = 0;
        }
	}
	//print();
	// Geser atas
	for(int i=0; i<n; i++){
        for(zeros=0; zeros <n && board[zeros][i] == 0; zeros++){}
        for(int j=0; j<n-zeros; j++){
            board[j][i] = board[j+zeros][i];
        }
        for(int j=n-zeros; j<n; j++){
            board[j][i] = 0;
        }
	}
	//print();
	// Geser kiri
	for(int i=0; i<n; i++){
        for(zeros=0; zeros <n && board[i][zeros] == 0; zeros++){}
        for(int j=0; j<n-zeros; j++){
            board[i][j] = board[i][j+zeros];
        }
        for(int j=n-zeros; j<n; j++){
            board[i][j] = 0;
        }
	}
	//print();
	// Geser bawah
	for(int i=0; i<n; i++){
        for(zeros = n-1; zeros>=0 && board[zeros][i] == 0; zeros--){}
        for(int j=n-1; j>=n-1-zeros; j--){
            board[j][i] = board[j-n+1+zeros][i];
        }
        for(int j=n-2-zeros; j>=0; j--){
            board[j][i] = 0;
        }
	}
	//print();
	cur = 0;
	for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[i][j] > 0){
                cur++; nxt[cur] = board[i][j];
                vis[cur] = false; pangkat[cur] = 0;
            }
        }
	}
	for(int i=1; i<=cur; i++){
        if(!vis[i]){
            int now = i, cyc = 0, curpow;
            while(!vis[now]){
                vis[now] = true; cyc++; now = nxt[now];
            }
            //cout << cyc << endl;
            for(int i=2; i*i <= cyc; i++){
                curpow = 0;
                while(cyc % i == 0){
                    curpow++; cyc /= i;
                }
                while(pangkat[i] < curpow){
                    pangkat[i]++; ans = ans * i % mod;
                }
            }
            if(cyc > 1){ // cyc prima nich
                if(pangkat[cyc] == 0){
                    pangkat[cyc]++; ans = ans * cyc % mod;
                }
            }
        }
	}
	cout << ans << endl;
}

/*
1
2
3  4
5  6  7  8
9 10 11 12 13

1  4  7  8 13
2  6 11 12
3 10
5
9

1  4  7  8 13
   2  6 11 12
         3 10
            5
            9

           13
           12
         8 10
   4  7 11  5
1  2  6  3  9

13
12
8 10
4  7 11  5
1  2  6  3  9

2 12 3 8 5 4 10 2
*/
