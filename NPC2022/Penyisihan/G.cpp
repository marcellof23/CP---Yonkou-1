#include <bits/stdc++.h>

using namespace std;

int t, n;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while(t--){
        cin >> n;
        if(n%9){
            cout << n%9 << endl;
        }else{
            cout << 9 << endl;
        }
	}
}
