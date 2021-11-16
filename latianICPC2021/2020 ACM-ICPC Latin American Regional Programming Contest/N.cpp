#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    long long n, x = 0, y, ans = 0;
    string s;
    cin >> n;
    cin >> s; y = 0;
    for(int i=0; i<s.length(); i++){
        if('0' <= s[i] && s[i] <= '9'){
            y = 10*y + (s[i] - '0');
        }
    }
    x = y;
    while(n--){
        cin >> s; y = 0;
        for(int i=0; i<s.length(); i++){
            if('0' <= s[i] && s[i] <= '9'){
                y = 10*y + (s[i] - '0');
            }
        }
        x += y;
        ans += (x%100 > 0);
    }
    cout << ans << endl;
}
