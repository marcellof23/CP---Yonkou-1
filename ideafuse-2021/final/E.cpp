#include <bits/stdc++.h>
using namespace std;



int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
    long long t, n, k;
    cin >> t;
    for(int tt=1; tt<=t; tt++){
        cin >> n >> k;
        long long m = n;
        long long digits[10], nbdig = 0, mul[10];
        mul[0] = 1;
        while(n>0){
            digits[nbdig] = n%10;
            nbdig++;
            n /= 10;
        }
        for(int i=1; i<10; i++){
            mul[i] = mul[i-1]*9;
        }
        long long idx=0, mp[10];
        for(int i=0; i<10; i++){
            if(i==k){
                mp[i] = -1;
            }else{
                mp[i] = idx;
                idx++;
            }
        }
        bool found = false;
        long long ans = 0;
        while(nbdig>0){
            nbdig--;
            ans *= 9;
            if(found){
                ans += 8;
            }else if(mp[digits[nbdig]]<0){
                found = true;
                if(k == 0){
                    ans -= 9;
                    ans += 8;
                }else{
                    ans += mp[digits[nbdig]-1];
                }
            }else{
                ans += mp[digits[nbdig]];
            }
        }
        if(m >= 10*k){
            ans++;
        }
        long long mul9 = 9, mul10 = 10;
        if(k==0){
            while(m>=mul10){
                ans += mul9;
                mul10 *= 10;
                mul9 *= 9;
            }
        }
        cout << "Case #" << tt << ": " << ans << endl;
    }
	return 0;
}
