#include <bits/stdc++.h>
using namespace std;

long long t, n, x, y, curx, cury, ans;
string s;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string pat, txt;
    cin >> t;
    for(int tt=1; tt<=t; tt++){
        cin >> n >> s;
        cin >> x >> y;
        curx = 0; cury = 0;
        ans = abs(x) + abs(y);
        for(int i=0; i<n; i++){
            if(s[i] == 'N'){
                cury++;
            }else if(s[i] == 'E'){
                curx++;
            }else if(s[i] == 'S'){
                cury--;
            }else{
                curx--;
            }
            //cout << curx << " " << cury << endl;
            ans = min(abs(x-curx) + abs(y-cury), ans);
        }
        cout << "Case #" << tt << ": " << ans << endl;
    }
}
