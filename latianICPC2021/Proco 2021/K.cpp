#include <bits/stdc++.h>
using namespace std;
#define ll long long

long long n, k, black[1000069], nb;
char c;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n >> k;
    nb = 0;
    for(int i=0; i<n; i++){
        cin >> c;
        if(c == 'B'){
            black[nb] = i;
            nb++;
        }
    }
    if(nb<=k){
        cout << n-nb << endl;
    }else{
        long long ans = 1e18;
        for(int i=0; i<k+1; i++){
            ans = min(ans, black[i+nb-k-1]-black[i]+1);
        }
        cout << n-ans-k << endl;
    }
}
