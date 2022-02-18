#include <bits/stdc++.h>
using namespace std;

long long c2(long long x){
    return x*(x-1)/2;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	long long n;
	double p;
	cin >> n >> p;
	long long lp = p*10000;
	for(int i=0; i<=n; i++){
        if(c2(n-i)*10000 <= c2(n)*(10000-lp)){
            cout << i << endl;
            return 0;
        }
	}
}
