#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    long long l, r, p;
    cin >> l >> r >> p;
    if(l<r){
        if(l*100 >= r*p){
            cout << "Ambidextrous" << endl;
        }else{
            cout << "Right-handed" << endl;
        }
    }else{
        if(r*100 >= l*p){
            cout << "Ambidextrous" << endl;
        }else{
            cout << "Left-handed" << endl;
        }
    }
}
