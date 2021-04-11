#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
	long long X, Y;
	long long x[30], y[30], ans, pw3[30], pw2[30], onex[30], oney[30], nbx, nby;
	long long prex[31], prey[31];

	pw3[0] = 1;
	pw2[0] = 1;
	for(int i=1; i<30; i++){
		pw3[i] = pw3[i-1]*3;
		pw2[i] = pw2[i-1]*2;
	}

	cin >> X >> Y;
	nbx=0;
	nby=0;
	prex[0] = 0;
	prey[0] = 0;
	for(int i=0; i<30; i++){
		x[i] = X%2;
		y[i] = Y%2;
		onex[nbx] = X%2;
		oney[nby] = Y%2;
		nbx += X%2;
		nby += Y%2;
		prex[i+1] = prex[i] + x[i];
		prey[i+1] = prey[i] + y[i];
		X /= 2;
		Y /= 2;
	}
	long long ox, oy;
	ans = 0;
	cout << nbx << nby << endl;
	for(int i=0; i<nbx; i++){
		for(int j=0; j<nby; j++){
			ox = onex[i];
			oy = oney[j];
			if(ox<oy){
				ans += pw3[ox]*pw2[oy-ox-prex[oy]+prex[ox]];
			}else{
				ans += pw3[oy]*pw2[ox-oy-prey[ox]+prey[oy]];
			}
		}
	}
}