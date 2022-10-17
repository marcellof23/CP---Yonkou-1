#include <bits/stdc++.h>

using namespace std;
int p[2], w, curp[2];
bool found, inv;
int nbkalah, dseri;
int totkalah, totmenang;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> p[0] >> p[1] >> w;
	inv = (w == 2);
    if(inv){ //Pokoknya kode nganggap player 1 yg menang
        int temp = p[0];
        p[0] = p[1];
        p[1] = temp;
    }

    found = false;
    for(nbkalah=0; !found && nbkalah<4; nbkalah++){
        for(totkalah = 0; !found && totkalah<=9*nbkalah; totkalah++){
            for(totmenang = 0; !found && totmenang<=36; totmenang++){
                curp[0] = 44 + totkalah;
                curp[1] = 11*nbkalah + totmenang;
                if(curp[0]-curp[1] == p[0]-p[1]){
                    dseri = p[0]-curp[0];
                    if(dseri == 0){
                        //cout << nbkalah << " " << totmenang << " " << totkalah << endl;
                        found = true;
                    }else if(dseri > 0 && max(totmenang, totkalah) >= 9){
                        //cout << nbkalah << " " << totmenang << " " << totkalah << endl;
                        found = true;
                    }
                }
            }
        }
    }
    nbkalah--; totkalah--; totmenang--;
    //cout << "AFTER" << endl;
    //cout << nbkalah << " " << totmenang << " " << totkalah << endl;
    if(!found){
        cout << -1 << endl;
    }else if(inv){
        cout << nbkalah << " 4" << endl;
        for(int i=0; i<nbkalah; i++){
            if(dseri > 0 && totkalah >= 9){
                cout << 11+dseri << " " << 9+dseri << endl;
                totkalah -= 9;
                dseri = 0;
            }else{
                cout << "11 " << min(totkalah, 9) << endl;
                totkalah = max(0, totkalah-9);
            }
        }
        for(int i=0; i<4; i++){
            if(dseri > 0 && totmenang >= 9){
                cout << 9+dseri << " " << 11+dseri << endl;
                totmenang -= 9;
                dseri = 0;
            }else{
                cout << min(totmenang, 9) << " 11" << endl;
                totmenang = max(0, totmenang-9);
            }
        }
    }else{
        cout << "4 " << nbkalah << endl;
        for(int i=0; i<nbkalah; i++){
            if(dseri > 0 && totkalah >= 9){
                cout << 9+dseri << " " << 11+dseri << endl;
                totkalah -= 9;
                dseri = 0;
            }else{
                cout << min(totkalah, 9) << " 11" << endl;
                totkalah = max(0, totkalah-9);
            }
        }
        for(int i=0; i<4; i++){
            if(dseri > 0 && totmenang >= 9){
                cout << 11+dseri << " " << 9+dseri << endl;
                totmenang -= 9;
                dseri = 0;
            }else{
                cout << "11 " << min(totmenang, 9) << endl;
                totmenang = max(0, totmenang-9);
            }
        }
    }
}
