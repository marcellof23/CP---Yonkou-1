#include <bits/stdc++.h>
using namespace std;

const int maxn = 1024;
int len[2][2];
int r, c, x, y;
int sum[1024][1024], dpsum[2][1024][1024];
int maxrc[2][2][1024], dpmaxrc[2][2][2][1024];
void init(){
    for(int i=0; i<1024; i++){
        maxrc[0][0][i] = 0;
        maxrc[0][1][i] = 0;
        maxrc[1][0][i] = 0;
        maxrc[1][1][i] = 0;
    }
}

int getmax(int id, int isCol, int lo, int hi){
    int ret = 0;
    if(lo>=0){
        ret = max(dpmaxrc[id][isCol][0][lo], ret);
    }
    if(hi<=len[id][isCol]){
        ret = max(dpmaxrc[id][isCol][1][hi], ret);
    }
    return ret;
}

int main() {
    cin >> r >> c;
    cin >> x >> y;
    len[0][0] = r-x;
    len[0][1] = c-y;
    len[1][0] = r-y;
    len[1][1] = c-x;
    // calc dp
    for(int i=0; i<=r; i++){
        for(int j=0; j<=c; j++){
            if(min(i, j)==0){
                sum[i][j] = 0;
            }else{
                cin >> sum[i][j];
                sum[i][j] += sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1];
            }
        }
    }
    init();
    //itung dp1 dan dp2
    for(int i=0; i<=r-x; i++){
        for(int j=0; j<=c-y; j++){
            dpsum[0][i][j] = sum[i+x][j+y] - sum[i+x][j] - sum[i][j+y] + sum[i][j];
            maxrc[0][0][i] = max(maxrc[0][0][i], dpsum[0][i][j]);
            maxrc[0][1][j] = max(maxrc[0][1][j], dpsum[0][i][j]);
            //cout << dpsum[0][i][j] << " ";
        }//cout << endl;
    }
    for(int i=0; i<=r-y; i++){
        for(int j=0; j<=c-x; j++){
            dpsum[1][i][j] = sum[i+y][j+x] - sum[i+y][j] - sum[i][j+x] + sum[i][j];
            maxrc[1][0][i] = max(maxrc[1][0][i], dpsum[1][i][j]);
            maxrc[1][1][j] = max(maxrc[1][1][j], dpsum[1][i][j]);
            //cout << dpsum[1][i][j] << " ";
        }//cout << endl;
    }
    //itung max
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            dpmaxrc[i][j][0][0] = maxrc[i][j][0];
            dpmaxrc[i][j][1][len[i][j]] = maxrc[i][j][len[i][j]];
            for(int k=1; k<=len[i][j]; k++){
                dpmaxrc[i][j][0][k] = max(dpmaxrc[i][j][0][k-1], maxrc[i][j][k]);
                dpmaxrc[i][j][1][len[i][j]-k] = max(dpmaxrc[i][j][1][len[i][j]-k+1], maxrc[i][j][len[i][j]-k]);
            }
        }
    }

    int ans = 0, maxr, maxc;
    for(int i=0; i<=r-x; i++){
        for(int j=0; j<=c-y; j++){
            maxr = max(getmax(0,0,i-x,i+x+1), getmax(1,0,i-y,i+x+1));
            maxc = max(getmax(0,1,j-y,j+y+1), getmax(1,1,j-x,j+y+1));
            ans = max(max(maxr,maxc)+dpsum[0][i][j], ans);
        }
    }
    for(int i=0; i<=r-y; i++){
        for(int j=0; j<=c-x; j++){
            maxr = max(getmax(0,0,i-x,i+y+1), getmax(1,0,i-y,i+y+1));
            maxc = max(getmax(0,1,j-y,j+x+1), getmax(1,1,j-x,j+x+1));
            ans = max(max(maxr,maxc)+dpsum[1][i][j], ans);
        }
    }
    cout << ans << endl;
}
