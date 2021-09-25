#include <bits/stdc++.h>
using namespace std;

long long n, m;
pair <long long, long long> findCor(long long idx, bool isX){

}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    bool inv = (m%2);
    if(inv){
        long long temp = n;
        n = m;
        m = temp;
    }
    char c;
    long long k = n*m;
    long long xx = 0, xy = 0, ox = 2, oy = 0;
    if(n <= 2){
        ox = 0;
        oy = 1;
    }
    while(k--){
        cin >> c;
        if(c == 'X'){
            if(inv){
                cout << xy+1 << " " << xx+1 << endl;
            }else{
                cout << xx+1 << " " << xy+1 << endl;
            }
            cout << flush;
            if(xx%2){xx += 3;}
            else{xx++;}
            if(xx>=n){
                xy++; xx=0;
                if(xy%2){
                    xx=2;
                    if(n<=2){
                        xy++; xx=0;
                    }
                }
            }
        }else{
            if(inv){
                cout << oy+1 << " " << ox+1 << endl;
            }else{
                cout << ox+1 << " " << oy+1 << endl;
            }
            if(ox%2){ox += 3;}
            else{ox++;}
            if(ox>=n){
                oy++; ox=0;
                if(oy%2 == 0){
                    ox=2;
                    if(n<=2){
                        oy++; ox=0;
                    }
                }
            }
        }
    }
	return 0;
}
