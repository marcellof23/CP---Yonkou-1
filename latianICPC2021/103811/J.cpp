#include <bits/stdc++.h>

using namespace std;
long long p[4], w[4] = {5, 15, 20, 6};
long long koef = 0, kons = 0;
double x;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> x;
    for(int i=0; i<4; i++){
        cin >> p[i];
    }
    x = 1e9;
    for(int i=0; i<16; i++){
        int cpy = i;
        koef = 0; kons = 0;
        for(int j=0; j<4; j++){
            if(cpy%2){
                koef += p[j];
                kons += p[j];
            }else{
                kons += p[j] * w[j];
            }
            //cout << cpy%2;
            cpy /= 2;
        }
        //cout << endl;
        //cout << "100x = " << koef << "x + " << kons << endl;
        if(koef < 100){
            x = min((double)kons/(100-koef), x);
        }
    }
    cout << fixed << setprecision(9) << x << endl;
}
