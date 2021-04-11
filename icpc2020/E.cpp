#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+6;
int n;
bool a[maxn];
int pref[maxn], suf[maxn];
int ans = 0;
bool ada0 = 0, ada1 = 0;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	for (int i=1; i<n; i++) cin >> a[i];
	for (int i=1; i<n; i++){
		if (a[i]) ada1 = 1;
		else ada0 = 1;
	}
	if (!ada1){
		cout << n-1 << "\n";
		return 0;
	}
	if (!ada0){
		cout << 1 << "\n";
		return 0;
	}
	pref[0] = maxn;
	for (int i=1; i<n; i++){
		if (a[i]) pref[i] = i;
		else pref[i] = pref[i-1];
	}
	suf[n] = maxn;
	for (int i=n-1; i>0; i--){
		if (a[i]) suf[i] = i;
		else suf[i] = suf[i+1];
	}
	for (int i=1; i<n; i++) cout << pref[i] << " ";
	cout << "\n";
	for (int i=1; i<n; i++) cout << suf[i] << " ";
	cout << "\n";
	for (int i=1; i<n; i++){
		if (!a[i]){
			if (pref[i]==maxn && suf[i]==maxn) continue;
			else if (pref[i]!=maxn && suf[i]==maxn) ans = max(ans,i-pref[i]);
			else if (pref[i]==maxn && suf[i]!=maxn) ans = max(ans,suf[i]-i);
			else ans = max(ans,min(i-pref[i],suf[i]-i));
		}
	}
	cout << ans << "\n";
}