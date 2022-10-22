#include <bits/stdc++.h>
using namespace std;

const int maxn = 262144;
int n, k, a;
bool bit[maxn][30], orz[30], nd;
int stck[30], nbstck = 0;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for(int i=0; i<n; i++){
        cin >> a;
        for(int j=0; j<30; j++){
            bit[i][j] = a%2; a/= 2;
        }
	}
	int ans = 0; nbstck = 0;
	for(int i=29; i>=0; i--){
        // coba masukin stck
        stck[nbstck] = i; nbstck++;
        a = 0;
        for(int j=0; j<nbstck; j++){
            orz[j] = false;
        }
        if(i < 4){
            //cout << "proses " << i << endl;
        }
        for(int j=0; j<n; j++){
            nd = true;
            for(int k=0; k<nbstck; k++){
                orz[k] = orz[k] || bit[j][stck[k]];
                nd = nd && orz[k];
            }
            //cout << j << " " << nd << endl;
            if(nd){
                a++;
                for(int k=0; k<nbstck; k++){
                    orz[k] = false;
                }
            }
        }
        if(i < 4){
            //cout << "ak: " << a << " " << k << endl;
        }
        if(a < k){
            nbstck--;
        }else{
            ans += (1<<i);
        }
	}
	cout << ans << endl;
}
