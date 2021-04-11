#include <bits/stdc++.h>
using namespace std;

long long mod = 998244353;

bool sieve[300069];

int main(){
	for(int i=0; i<300069; i++){
		sieve[i] = true;
	}
	for(int i=2; i<300069; i++){
		if(sieve[i]){
			for(int j=2*i; j<300069; j+=i){
				sieve[j] = false;
			}
		}
	}
	long long n;
	cin >> n;
	long long p[n+1], vis[n+1];
	for(int i=1; i<=n; i++){
		cin >> p[i];
		vis[i] = false;
	}
	long long fnv = 1, curnode, lenc;
	long long kpk[100069];
	for(int i=0; i<100069; i++){
		kpk[i] = 0;
	}
	long long pw, pwcounter, curpw, ppw, add=0, curadd;
	while(fnv <= n){
		curnode = fnv;
		lenc = 0;
		while(!vis[curnode]){
			lenc++;
			vis[curnode] = true;
			curnode = p[curnode];
		}
		curadd = 0;
		while(lenc%2==0){
			lenc /= 2;
			curadd++;
		}
		add = max(add, curadd);
		pwcounter = 1;
		pw = 1;
		while((pwcounter*2-1)%lenc != 0){
			pw++;
			pwcounter = pwcounter*2%lenc;
		}
		for(int i=2; i*i<=pw; i++){
			if(sieve[i]){
				ppw = 0;
				while(pw%i == 0){
					ppw++;
					pw /= i;
				}
				kpk[i] = max(kpk[i], ppw);
			}
		}
		kpk[pw] = max(kpk[pw], 1ll);
		while(fnv <= n && vis[fnv]){
			fnv++;
		}
	}
	long long ans = 1;
	for(int i=2; i<100069; i++){
		while(kpk[i]>0){
			ans = ans*i%mod;
			kpk[i]--;
		}
	}
	cout << ans+add << endl;
	return 0;
}