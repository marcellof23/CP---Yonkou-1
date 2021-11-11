#include <bits/stdc++.h>
using namespace std;
#define ll long long

long long n, x, y;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n >> x >> y;
    long long arr[y], m;
    arr[0] = x;
    if(x+y-1 <= n && n <= x*y){
        m = n-(x+y-1);
        n -= arr[0];
        for(int j=1; j<=arr[0]; j++){
            cout << n+j << ' ';
        }
        for(int i=1; i<y; i++){
            arr[i] = 1+ min(x-1, m);
            m -= min(x-1, m);
            //cout << arr[i] << endl;
            n -= arr[i];
            for(int j=1; j<=arr[i]; j++){
                cout << n+j << ' ';
            }
        }cout << endl;
    }else{
        cout << -1 << endl;
    }
}
