#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    bool left[10][2] = {{1,1},{0,0},{0,1},{0,0},{1,0},{1,0},{1,1},{0,0},{1,1},{1,0}};
    bool right[10][2] = {{1,1},{1,1},{1,0},{1,1},{1,1},{0,1},{0,1},{1,1},{1,1},{1,1}};
    long long dig[10] = {6,2,5,5,4,5,6,3,7,6};
    long long n, x, ans;
    cin >> n;
    while(n--){
        cin >> x;
        ans = dig[x/10] + dig[x%10];
        if(x/10 != 1 && left[x%10][0] == right[x/10][0] && left[x%10][1] == right[x/10][1]){
            ans -= left[x%10][0];
            ans -= left[x%10][1];
        }
        cout << ans << endl;
    }
}
