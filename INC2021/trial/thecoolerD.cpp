#include <bits/stdc++.h>
using namespace std;
#define ll long long

const long long nmax = 131072, mod = 1e9+7;
long long segtree[3][2*nmax], lazy[3][2*nmax], range[2*nmax][2];

void build(){
    for(int i=0; i<nmax; i++){
        for(int j=0; j<3; j++){
            segtree[j][i] = 0;
            segtree[j][i+nmax] = 0;
            lazy[j][i] = 0;
            lazy[j][i+nmax] = 0;
        }
        range[nmax+i][0] = i;
        range[nmax+i][1] = i;
    }
    for(int i=nmax-1; i>0; i--){
        range[i][0] = range[2*i][0];
        range[i][1] = range[2*i+1][1];
    }
}
void update(long long id, long long lo, long long hi, long long val){

}
long long query(long long id, long long lo, long long hi){

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

}
