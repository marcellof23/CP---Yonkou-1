#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool can[250069];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    for(int i=1; i<250069; i++){
        can[i] = false;
    }
    can[0] = true;
    int n, a, nb2 = 0, tot = 0;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a;
        if(a == 2){
            nb2++;
        }else{
            tot += a;
            for(int j=250068-a; j>=0; j--){
                if(can[j]){
                    can[j+a] = true;
                }
            }
        }
    }
    if(tot%2){
        cout << "NO" << endl;
    }else{
        if(can[tot/2]){
            cout << "YES" << endl;
            return 0;
        }
        for(int i=1; i<=nb2; i++){
            for(int j=250066; j>=0; j--){
                if(can[j]){
                    can[j+2] = true;
                }
            }
            if(can[tot/2+i]){
                cout << "YES" << endl;
                return 0;
            }
        }
        cout << "NO" << endl;
    }
}
