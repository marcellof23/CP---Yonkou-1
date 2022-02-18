#include <bits/stdc++.h>
using namespace std;
#define ll long long

long long a[6];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    for(int i=0; i<6; i++){
        cin >> a[i];
    }
    sort(a, a+6);
    long long dif = 1e18;
    for(int i=1; i<6; i++){
        dif = min(dif, a[i] - a[i-1]);
    }
    if(dif==0){
        cout << a[0] << endl;
        return 0;
    }
    if(a[5] - a[0] == 5 * dif){
        if(a[0]-dif>0){cout << a[0]-dif << endl;}
        cout << a[5]+dif << endl;
        return 0;
    }
    for(int i=1; i<6; i++){
        if(a[i] != a[0] + i*dif){
            cout << a[0] + i*dif << endl;
            return 0;
        }
    }
}
