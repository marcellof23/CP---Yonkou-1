#include <bits/stdc++.h>
using namespace std;

const int maxn = 1024;
int n, m;
string board[maxn];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	if(n<3){
        for(int i=0; i<n*n; i++){
            if(i < m){
                cout << 'w';
            }else{
                cout << 'u';
            }
            if(i%n == n-1){
                cout << endl;
            }
        }
	}else if(2*m <= n*n){//w dikit
        for(int i=0; i<n; i++){
            board[i] = "";
            for(int j=0; j<n; j++){
                board[i] += "u";
            }
        }
        if(m <= ((n-2)*(n-2)+1)/2 + (n-2)/2*4){
            for(int i=1; i<n-1; i++){
                for(int j=1; j<n-1; j++){
                    if(((i+j)%2 == 0) && (m>0)){
                        m--; board[i][j] = 'w';
                    }
                }
            }
            for(int i=1; i<n-1; i++){
                if((i%2==0) && (m>0)){
                    m--; board[0][i] = 'w';
                }
                if((i%2==0) && (m>0)){
                    m--; board[i][0] = 'w';
                }
                if(((n-1+i)%2==0) && (m>0)){
                    m--; board[n-1][i] = 'w';
                }
                if(((n-1+i)%2==0) && (m>0)){
                    m--; board[i][n-1] = 'w';
                }
            }
        }else{
            for(int i=1; i<n-1; i++){
                for(int j=1; j<n-1; j++){
                    if(((i+j)%2) && (m>0)){
                        m--; board[i][j] = 'w';
                    }
                }
            }
            for(int i=1; i<n-1; i++){
                if((i%2) && (m>0)){
                    m--; board[0][i] = 'w';
                }
                if((i%2) && (m>0)){
                    m--; board[i][0] = 'w';
                }
                if(((n-1+i)%2) && (m>0)){
                    m--; board[n-1][i] = 'w';
                }
                if(((n-1+i)%2) && (m>0)){
                    m--; board[i][n-1] = 'w';
                }
            }
            if((n%2==0) && m>0){
                m--; board[0][n-1] = 'w';
            }
            if((n%2==0) && m>0){
                m--; board[n-1][0] = 'w';
            }
        }
        for(int i=0; i<n; i++){
            cout << board[i] << endl;
        }
	}else{ // n dikit
	    for(int i=0; i<n; i++){
            board[i] = "";
            for(int j=0; j<n; j++){
                board[i] += "w";
            }
        }
        for(int i=0; i<n; i+=2){
            for(int j=0; j<i; j+=2){
                if(m < n*n){
                    m++; board[i][j] = 'u';
                }
            }
            for(int j=0; j<=i; j+=2){
                if(m < n*n){
                    m++; board[j][i] = 'u';
                }
            }
        }
        for(int i=1; i<n; i+=2){
            for(int j=1; j<i; j+=2){
                if(m < n*n){
                    m++; board[i][j] = 'u';
                }
            }
            for(int j=1; j<=i; j+=2){
                if(m < n*n){
                    m++; board[j][i] = 'u';
                }
            }
        }
        for(int i=0; i<n; i++){
            cout << board[i] << endl;
        }
	}
}
