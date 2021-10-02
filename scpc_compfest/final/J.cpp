#include <bits/stdc++.h>
using namespace std;

long long n, m, k;
long long a[1069][1069];
long long down[1069][1069];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
            if(a[i][j] == 2){
                down[i][j] = i+1;
            }else{
                down[i][j] = i;
            }
        }
    }
    long long x, y, z;
    while(k--){
        x = 0; cin >> y; y--;
        while(x<n){
            if(a[x][y] == 1){
                a[x][y] = 2;
                down[x][y] = x+1;
                y++;
            }else if(a[x][y] == 3){
                a[x][y] = 2;
                down[x][y] = x+1;
                y--;
            }else if(down[x][y]<n){
                z = down[x][y];
                down[x][y] = down[z][y];
                x = z;
            }else{
                x = down[x][y];
            }
        }
        cout << y+1 << " ";
    }
    cout << endl;
	return 0;
}
