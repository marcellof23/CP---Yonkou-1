#include <bits/stdc++.h>
using namespace std;

long long ans[10069][10069];
string s1, s2;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    getline(cin, s1);
    getline(cin, s2);
    long long n = s1.length();
    long long m = s2.length();
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(min(i, j)==0){
                ans[i][j] = max(i, j);
            }else if(s1[i-1]==s2[j-1]){
                ans[i][j] = ans[i-1][j-1];
            }else{
                ans[i][j] = 1 + min(min(ans[i][j-1], ans[i-1][j]), ans[i-1][j-1]);
            }
        }
    }
    cout << ans[n][m] << endl;
}
