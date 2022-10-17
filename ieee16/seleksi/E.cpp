#include <bits/stdc++.h>

using namespace std;

const long long maxn = 3069;
long long n, a[maxn], ans, sum;
long long idx, cursum;
bool nemu = false;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i=0; i<n; i++){
        cin >> a[i];
	}
	sum = 0;
	nemu = false;
	for(int i=0; i<n-1 && !nemu; i++){
        //cout << sum << " ";
        sum += a[i];
        ans = i;
        //cout << "sumans " << sum << " " << ans << endl;

        idx = i+1;
        cursum = a[idx];

        nemu = true;
        while(idx < n-1 && nemu){
            //cout << "idx " << idx << " " << cursum << endl;
            if(cursum < sum){
                ans++; cursum += a[idx+1];
            }else if(cursum > sum){
                nemu = false;
            }else{
                idx++;
                cursum = a[idx];
            }
            idx++;
        }
        nemu = (cursum == sum);
	}
	if(nemu){
        cout << ans << endl;
	}else{
        cout << n-1 << endl;
    }
}
