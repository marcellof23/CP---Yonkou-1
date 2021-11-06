#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    long long n;
    cin >> n;
    long long perm[n], a[n], tot=1;
    for(int i=0; i<n; i++){
        cin >> a[i];
        perm[i] = i;
        tot *= (i+1);
    }
    for(int i=0; i<tot; i++){
        long long cur = 0;
        bool can = true;
        for(int j=0; j<n; j++){
            cur += a[perm[j]];
            can = can && (0 <= cur) && (cur <= 99999999);
        }
        if(can){
            for(int j=0; j<n; j++){
                cout << a[perm[j]] << endl;
            }
            return 0;
        }
        next_permutation(perm, perm+n);
    }
    cout << "Error" << endl;
}
