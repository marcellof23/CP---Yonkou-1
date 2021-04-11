#include <bits/stdc++.h>
using namespace std;

long long mod = 235813;
long long pangkat(long long a, long long b){
	long long pw[20];
	pw[0] = a;
	for(int i=1; i<20; i++){
		pw[i] = pw[i-1]*pw[i-1]%mod;
	}
	long long c = b;
	long long cur = 0;
	long long res = 1;
	while(c>0){
		if(c%2==1){
			res = res*pw[cur]%mod;
		}
		cur++;
		c/=2;
	}
	return res;
}
long long inv(long long a){
	return pangkat(a, mod-2);
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	long long n;
	cin >> n;
	long long a[n], c[n];
	c[0] = 1;
	for(int i=1; i<n; i++){
		c[i] = c[i-1]*(n-i)%mod;
		c[i] = c[i]*inv(i)%mod;
	}
	for(int i=0; i<n; i++){
		if(i%2 == n%2){
			c[i] = mod-c[i];
		}
	}
	long long sum = 0;
	for(int i=0; i<n; i++){
		cin >> a[i];
		a[i] %= mod;
		sum = (sum + a[i]*c[i])%mod;
	}
	long long rep, ans = 0;
	if(sum==0){
		cout << 0 << endl;
	}else{
		for(int i=0; i<n; i++){
			rep = (sum*inv(c[i]))%mod;
			rep = (a[i]-rep+mod)%mod;
			if(rep<=100000 || rep-mod>=-100000){
				ans++;
			}
		}
		cout << ans << endl;
	}
}
	