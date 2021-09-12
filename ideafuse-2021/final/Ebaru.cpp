#include <bits/stdc++.h>
using namespace std;



int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
    long long t, n, k;
    cin >> t;
    for(int tt=1; tt<=t; tt++){
        cin >> n >> k;
        long long digits[9], idx=0;
        for(int i=0; i<10; i++){
            if(i!=k){
                digits[idx] = i;
                idx++;
            }
        }
        long long lft = 0, rght = 2*n;

        while(rght-lft>1){
            long long mid = (lft+rght)/2;
            long long cpmid = mid;
            long long res = 0, mul = 1;
            while(mid>0){
                res += digits[mid%9] * mul;
                mul *= 10;
                mid /= 9;
            }
            if(k==0){
                res += mul;
            }
            if(res<=n){
                lft = cpmid;
            }else{
                rght = cpmid;
            }
        }
        long long mul9 = 9, mul10 = 10;
        if(n >= 10*k){
            lft++;
        }
        if(k==0){
            while(n>=mul10){
                lft += mul9;
                mul10 *= 10;
                mul9 *= 9;
            }
        }
        cout << "Case #" << tt << ": " << lft << endl;
    }
	return 0;
}
