#include <bits/stdc++.h>
using namespace std;
#define ll long long

long long n;
long long a[1010];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n;
    bool dec = false;
    bool bisa = true;
    cin >> a[0];
    for(int i=1; i<n; i++){
        cin >> a[i];
        if(a[i]<a[i-1]){
            if(dec){
                bisa = false;
            }else{
                dec = true;
            }
        }
    }
    if(dec && a[n-1]>a[0]){
        bisa = false;
    }
    if(bisa){
        cout << "Phew" << endl;
    }else{
        cout << "Lie" << endl;
    }
}
