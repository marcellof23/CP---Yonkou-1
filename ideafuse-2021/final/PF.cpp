#include <bits/stdc++.h>
using namespace std;



int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	long long triangle[10000];
	triangle[0] = 0;
	for(int i=1; i<10000; i++){
        triangle[i] = triangle[i-1] + i;
	}
    long long t, n;
    cin >> t;
    string ans;
    for(int tt=1; tt<=t; tt++){
        cin >> n;
        ans = "NO";
        for(int i=3; triangle[i]<=n; i++){
            if((n-triangle[i])%triangle[i-1] == 0){
                ans = "YES";
            }
        }
        cout << "Case #" << tt << ": " << ans << endl;
    }
	return 0;
}
