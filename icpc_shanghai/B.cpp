#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	long long n, m, k=0;
	cin >> n >> m;
	string old[n];
	string s;
	for(int i=0; i<n; i++){
		cin >> old[i];
	}
	for(int i=0; i<n; i++){
		cin >> s;
		for(int j=0; j<m; j++){
			if(s[j] != old[i][j]){
				k++;
			}
		}
	}
	if(2*k<=n*m){
		for(int i=0; i<n; i++){
			cout << old[i] << endl;
		}
	}else{
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(old[i][j]=='.'){
					cout << 'X';
				}else{
					cout << '.';
				}
			}
			cout << endl;
		}
	}
}