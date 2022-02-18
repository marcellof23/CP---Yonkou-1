#include <bits/stdc++.h>
using namespace std;

long long sv[1000069];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for(int i=1; i<1000069; i++){
        sv[i] = -i;
    }
    for(int i=1; i<1000069; i++){
        for(int j=1; i*j<1000069; j++){
            sv[i*j] += i;
        }
    }
    long long t, n;
    cin >> t;
    while(t--){
        cin >> n;
        if(sv[n]<n){
            cout << "deficient" << endl;
        }else if(sv[n]>n){
            cout << "abundant" << endl;
        }else{
            cout << "perfect" << endl;
        }
    }
}
