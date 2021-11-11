#include <bits/stdc++.h>
using namespace std;
#define ll long long

long long n, a, b, c, d;
long long cur, skor[2];
bool hor[9][10], ver[10][9];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n;
    cur = 0; skor[0] = 0; skor[1] = 0;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n; j++){
            hor[i][j] = false;
            ver[j][i] = false;
        }
    }
    long long ad;
    string ch[2];
    ch[0] = "A";
    ch[1] = "B";
    string s = "";
    for(int i=0; i<2*n*n-2*n; i++){
        s += ch[cur];
        cin >> a >> b >> c >> d;
        a--; b--; c--; d--;
        ad = 0;
        if(a == c){ //ver
            ver[a][min(b,d)] = true;
            if(a>0){
                ad += ver[a-1][min(b,d)] && hor[a-1][b] && hor[a-1][d];
            }
            if(a<n-1){
                ad += ver[a+1][min(b,d)] && hor[a][b] && hor[a][d];
            }
        }else{ //hor
            hor[min(a,c)][b] = true;
            if(b>0){
                ad += hor[min(a,c)][b-1] && ver[a][b-1] && ver[c][b-1];
            }
            if(b<n-1){
                ad += hor[min(a,c)][b+1] && ver[a][b] && ver[c][b];
            }
        }
        if(ad){
            skor[cur] += ad;
        }else{
            cur = (cur+1)%2;
        }
    }
    cout << s << endl;
    cout << skor[0] << ' ' << skor[1] << endl;
}
