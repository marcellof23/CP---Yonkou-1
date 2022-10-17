#include <bits/stdc++.h>
using namespace std;

const int maxn = 1048576;
int n, cur, dp[maxn];
string s;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> s; n = s.length();
    dp[n-1] = 0;
    dp[n-2] = 0;
    for(int i=n-3; i>=0; i--){
        dp[i] = dp[i+1];
        cur = 100*(s[i]-'0') + 10*(s[i+1]-'0') + (s[i+2]-'0');
        if(cur%8 == 0){
            dp[i]++;
        }
    }
    for(int i=0; i<n; i++){
        if((s[i] == '0') ||(s[i] == '8')){
            dp[i]++;
        }
        if((i<n-1) && ((10*(s[i]-'0') + ((int)s[i+1]-'0'))%8==0)){
            dp[i]++;
        }
        cout << dp[i] << " ";
    }
    cout << endl;
}
