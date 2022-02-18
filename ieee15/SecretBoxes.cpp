#include <bits/stdc++.h>
using namespace std;

long long t, n;
char c;
long long ans[1600], nb[1600];
pair<int, int> srt[1600];
string s;

int main() {
    cin >> t >> n;
    long long mul = n*n*n*n/8/30000;
    cout << mul << endl;
    while(t--){
        for(int i=1; i<=n; i++){
            nb[i] = 0;
        }
        for(int i=1; i<=n; i++){
            for(int j=i+1; j<=n; j++){
                for(int k=j+1; k<=n; k++){
                    for(int m=k+1; m<=n; m++){
                        cout << "? " << i << " " << j << " " << k << " " << m << endl;
                        cout << flush;
                        cin >> c;
                        nb[i] += (c=='>');
                        nb[j] += (c=='>');
                        nb[k] += (c=='<');
                        nb[m] += (c=='<');
                        cout << "? " << i << " " << k << " " << j << " " << m << endl;
                        cout << flush;
                        cin >> c;
                        nb[i] += (c=='>');
                        nb[j] += (c=='<');
                        nb[k] += (c=='>');
                        nb[m] += (c=='<');
                        cout << "? " << i << " " << m << " " << k << " " << j << endl;
                        cout << flush;
                        cin >> c;
                        nb[i] += (c=='>');
                        nb[j] += (c=='<');
                        nb[k] += (c=='<');
                        nb[m] += (c=='>');
                        m += mul;
                    }
                }
            }
        }
        for(int i=1; i<=n; i++){
            srt[i] = {nb[i], i};
        }
        sort(srt+1, srt+n+1);
        for(int i=1; i<=n; i++){
            ans[srt[i].second] = i;
        }
        cout << '!';
        for(int i=1; i<=n; i++){
            cout << ' ' << ans[i];
        }
        cout << endl;
        cout << flush;
        cin >> s;
    }
}
