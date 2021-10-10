#include <bits/stdc++.h>
using namespace std;

double c2(long long x){
    return x*(x-1)/2;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	long long n;
	double p;
	cin >> n >> p;
	for(int i=0; i<=n; i++){
        if(c2(n-i)/c2(n) <= (double)1-p){
            cout << i << endl;
            return 0;
        }
	}
}
