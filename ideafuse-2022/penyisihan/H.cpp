#include <bits/stdc++.h>
using namespace std;

#define ws lekurnopqwencvoiwue

long long t, n, x, y;
long long ns, es, ss, ws;
string s, ans, cur;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    for(int tt=1; tt<=t; tt++){
        cin >> n >> s; ans = s;
        for(int i=0; i<n; i++){
            ans[i] = 'Z';
        }
        cin >> y >> x;
        ns = 0; es = 0; ss = 0; ws = 0;
        for(int i=0; i<n; i++){
            ns += (s[i] == 'N');
            es += (s[i] == 'E');
            ss += (s[i] == 'S');
            ws += (s[i] == 'W');
        }
        //cout << ns << " " << es << " " << ss << " " << ws << endl;
        if((abs(x+y))%2 != s.length()%2){
            cout << "Case #" << tt << ": -1" << endl;
        }else if(abs(x) + abs(y) > s.length()){
            cout << "Case #" << tt << ": -1" << endl;
        }else{ // Pasti bisa
            int difx = abs(x - (ns-ss));
            int dify = abs(y - (es-ws));
            //cout << difx << " " << dify << endl;
            if(x > ns-ss){ // N preferable
                if(y > es-ws){ // E preferable
                    // S->N, S->E, W->N, W->E, urutan abjad = E, N, S, W
                    for(int diag=difx%2; diag <= min(difx, dify); diag+=2){
                        for(int j=0; j<=diag; j++){
                            int StoN = (difx - diag)/2;
                            int StoE = j;
                            int WtoN = diag-j;
                            int WtoE = (dify - diag)/2;
                            if(StoN + StoE <= ss && WtoN + WtoE <= ws){
                                cur = s;
                                for(int i=0; i<n; i++){
                                    if(cur[i] == 'S' && StoE > 0){
                                        cur[i] = 'E'; StoE--;
                                    }else if(cur[i] == 'S' && StoN > 0){
                                        cur[i] = 'N'; StoN--;
                                    }else if(cur[i] == 'W' && WtoE > 0){
                                        cur[i] = 'E'; WtoE--;
                                    }else if(cur[i] == 'W' && WtoN > 0){
                                        cur[i] = 'N'; WtoN--;
                                    }
                                }
                                ans = min(ans, cur);
                            }
                        }
                    }
                }else{ // W preferable
                    // S->N, S->W, E->N, E->W, urutan abjad = E, N, S, W
                    for(int diag=difx%2; diag <= min(difx, dify); diag+=2){
                        for(int j=0; j<=diag; j++){
                            int StoN = (difx - diag)/2;
                            int StoW = j;
                            int EtoN = diag-j;
                            int EtoW = (dify - diag)/2;
                            if(StoN + StoW <= ss && EtoN + EtoW <= es){
                                cur = s;
                                for(int i=0; i<n; i++){
                                    if(cur[i] == 'S' && StoN > 0){
                                        cur[i] = 'N'; StoN--;
                                    }
                                }
                                for(int i=n-1; i>=0; i--){
                                    if(cur[i] == 'S' && StoW > 0){
                                        cur[i] = 'W'; StoW--;
                                    } else if(cur[i] == 'E' && EtoW > 0){
                                        cur[i] = 'W'; EtoW--;
                                    } else if(cur[i] == 'E' && EtoN > 0){
                                        cur[i] = 'N'; EtoN--;
                                    }
                                }
                                ans = min(ans, cur);
                            }
                        }
                    }
                }
            }else{ // S preferable
                if(y > es-ws){ // E preferable
                    // N->S, N->E, W->S, W->E, urutan abjad = E, N, S, W
                    for(int diag=difx%2; diag <= min(difx, dify); diag+=2){
                        for(int j=0; j<=diag; j++){
                            int NtoS = (difx - diag)/2;
                            int NtoE = j;
                            int WtoS = diag-j;
                            int WtoE = (dify - diag)/2;
                            if(NtoS + NtoE <= ns && WtoS + WtoE <= ws){
                                cur = s;
                                for(int i=0; i<n; i++){
                                    if(cur[i] == 'N' && NtoE > 0){
                                        cur[i] = 'E'; NtoE--;
                                    } else if(cur[i] == 'W' && WtoE > 0){
                                        cur[i] = 'E'; WtoE--;
                                    } else if(cur[i] == 'W' && WtoS > 0){
                                        cur[i] = 'S'; WtoS--;
                                    }
                                }
                                for(int i=n-1; i>=0; i--){
                                    if(cur[i] == 'N' && NtoS > 0){
                                        cur[i] = 'S'; NtoS--;
                                    }
                                }
                                ans = min(ans, cur);
                            }
                        }
                    }
                }else{ // W preferable
                    // N->S, N->W, E->S, E->W, urutan abjad = E, N, S, W
                    for(int diag=difx%2; diag <= min(difx, dify); diag+=2){
                        for(int j=0; j<=diag; j++){
                            int NtoS = (difx - diag)/2;
                            int NtoW = j;
                            int EtoS = diag-j;
                            int EtoW = (dify - diag)/2;
                            if(NtoS + NtoW <= ns && EtoS + EtoW <= es){
                                cur = s;
                                for(int i=n-1; i>=0; i--){
                                    if(cur[i] == 'N' && NtoW > 0){
                                        cur[i] = 'W'; NtoW--;
                                    }else if(cur[i] == 'N' && NtoS > 0){
                                        cur[i] = 'S'; NtoS--;
                                    }else if(cur[i] == 'E' && EtoW > 0){
                                        cur[i] = 'W'; EtoW--;
                                    }else if(cur[i] == 'E' && EtoS > 0){
                                        cur[i] = 'S'; EtoS--;
                                    }
                                }
                                ans = min(ans, cur);
                            }
                        }
                    }
                }
            }
            cout << "Case #" << tt << ": " << ans << endl;
        }
    }
}
