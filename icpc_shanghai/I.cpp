#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	double n, m, pi, tp, unitc;
	cin >> n >> m; //n circle, m lines
	pi = acos(-1);
	tp = floor(2*m/pi);
	unitc = tp*(tp+1)*pi;
	unitc += 4*m*(m-tp)-2*m;
	double ans = n*(n+1)/2*unitc + m*n*(n+1);
	for(double i=1; i<n; i++){
		for(double j=i+1; j<=n; j++){
			ans += 4*m*(j-i) + 2*i*unitc;
		}
	}
	cout << fixed << setprecision(9) << ans << endl;
}