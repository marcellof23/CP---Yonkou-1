#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	long long a, b, c, d, e;
	long long mx = 1e9;
	cout << "? " << 1 << " " << 1 << endl;
	cin >> a;
	cout << "? " << 1 << " " << mx << endl;
	cin >> b;
	cout << "? " << mx << " " << 1 << endl;
	cin >> c;

	cout << "? " << 1 << " " << (1 + mx + a - b)/2 << endl;
	cin >> d;
	cout << "? " << (1 + mx + a - c)/2 << " " << 1 << endl;
	cin >> e;
	cout << "!";
	cout << 1 + a - e << " ";
	cout << 1 + a - d << " ";
	cout << mx - (c - e) << " ";
	cout << mx - (b - d) << " ";
}
