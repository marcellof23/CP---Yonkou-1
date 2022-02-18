#include <bits/stdc++.h>
using namespace std;
#define ll long long

long long n, a[100069], b[100069];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        cin >> b[i];
    }
    sort(a, a+n); sort(b, b+n);

    long long ia = n-1, ib = n-1, ans=0;
    while(ib>=0 && ia>=0){
        while(ib>=0 && b[ib]>=a[ia]){
            ib--;
        }
        if(ib>=0){
            ans++;
        }
        ia--; ib--;
    }
    cout << ans << endl;
}
