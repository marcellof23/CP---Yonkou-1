#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define point pair <double, double>
 
bool inln(point xy, point a, point b){
	return min(a.first, b.first) <= xy.first && xy.first <= max(a.first, b.first) && min(a.second, b.second) <= xy.second && xy.second <= max(a.second, b.second);
}
 
bool intersect(point a, point b, point c, point d){
	point g1 = {b.first-a.first, b.second-a.second};
	point g2 = {d.first-c.first, d.second-c.second};
	if(g1.first*g2.second ==  g1.second*g2.first){
		if(g2.second*(c.first-a.first) == g2.first*(c.second-a.second)){
			return inln(c, a, b) || inln(d, a, b) || inln(a, c, d) || inln(b, c, d);
		}else{
			return false;
		}
	}else{
		double k = (g2.second*(c.first-a.first) - g2.first*(c.second-a.second))/(g1.first*g2.second - g1.second*g2.first);
		double x = a.first + k*g1.first;
		double y = a.second + k*g1.second;
		point xy = {x, y};
		return inln(xy, a, b) && inln(xy, c, d);
	}
}
 
double distance (point a, point b){
	return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}
 
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	long long n;
	cin >> n;
	point p[n];
	double x, y;
	for(int i=0; i<n; i++){
		cin >> x >> y;
		p[i] = {x, y};
	}
	double prefdis[n];
	prefdis[0] = 0;
	for(int i=1; i<=n; i++){
		prefdis[i] = prefdis[i-1] + distance(p[i-1], p[i]);
	}
	double maxcut = 0, uncut;
	bool valid;
	for(int i=0; i<n-1; i++){
		for(int j=i+2; j<n; j++){
			uncut = prefdis[j] - prefdis[i];
			valid = true;
			for(int k=i+1; k<j-1; k++){
				valid = valid && !(intersect(p[i], p[j], p[k], p[k+1]));
			}
			if((p[j].second - p[i].second)*(p[i+1].first - p[i].first) == (p[j].first - p[i].first)*(p[i+1].second - p[i].second)){
				valid = valid && inln(p[i+1], p[i], p[j]);
			}
			if((p[j].second - p[i].second)*(p[i+1].first - p[i].first) == (p[j].first - p[i].first)*(p[i+1].second - p[i].second)){
				valid = valid && inln(p[i+1], p[i], p[j]);
			}
			if(valid){
				maxcut = max(maxcut, uncut - distance(p[i], p[j]));
			}
		}
	}
	cout << fixed << setprecision(9) << prefdis[n-1] - maxcut << endl;
}