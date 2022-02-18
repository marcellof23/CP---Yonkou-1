#include <bits/stdc++.h>
using namespace std;

int koef[100];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    for(int i=0; i<99; i++){
        koef[i] = 0;
    }
    string s, x = "", ad = " ";
    int a, b, mul = 1;
    cin >> s;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '+' || s[i] == '-'){
            bool beforex = true;
            a = 0; b = 0;
            for(int i=0; i<x.length(); i++){
                if(beforex){
                    if(x[i] == 'x'){
                        beforex = false;
                    }else{
                        a = a*10 + (x[i] - '0');
                    }
                }else{
                    b = b*10 + (x[i] - '0');
                }
            }
            if(x[0] == 'x'){a = 1;}
            //cout << mul*a << " " << b << endl;
            koef[b] = mul*a;
            if(s[i] == '+'){
                mul = 1;
            }else{
                mul = -1;
            }
            x = "";
        }else{
            ad[0] = s[i];
            x += ad[0];
        }
    }
    bool beforex = true;
    a = 0; b = 0;
    for(int i=0; i<x.length(); i++){
        if(beforex){
            if(x[i] == 'x'){
                beforex = false;
            }else{
                a = a*10 + (x[i] - '0');
            }
        }else{
            b = b*10 + (x[i] - '0');
        }
    }
    if(x[0] == 'x'){a = 1;}
    //cout << mul*a << " " << b << endl;
    koef[b] = mul*a;

    //turunin
    for(int i=0; i<99; i++){
        koef[i] = (i+1)*koef[i+1];
    }
    for (int k=99; k>=0; k--){
    if (koef[k] == 0) continue;
     if (k == 0){
      if (koef[k] > 0) cout << "+" << koef[k];
      else cout << koef[k];
     }
     else{
      if (koef[k] == -1) cout << "-x" << k;
      else if (koef[k] == 1) cout << "+x" << k;
      else{
       if (koef[k] > 0) cout << "+" << koef[k] << "x" << k;
       else cout << koef[k] << "x" << k;
      }
     }
    }
}
