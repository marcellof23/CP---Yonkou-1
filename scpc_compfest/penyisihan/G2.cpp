#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+4, maxm = 1e5+4;
int n, m;
pair<int, int> e[maxm];
int cnt[2];

int main(){
	cin >> n >> m;
	memset(cnt, 0, sizeof cnt);
	for (int i=0; i<m; i++){
		cin >> e[i].first >> e[i].second;
		cnt[e[i].first > e[i].second]++;
	}
	if (cnt[0] < cnt[1]){
		cout << cnt[0] << '\n';
		for (int i=0; i<m; i++){
			if (e[i].first < e[i].second) cout << i+1 << '\n';
		}
	}
	else{
		cout << cnt[1] << '\n';
		for (int i=0; i<m; i++){
			if (e[i].first > e[i].second) cout << i+1 << '\n';
		}
	}
}

/*
2 7
1 2
1 2
1 2
1 2
2 1
2 1
2 1

3 8
2 3
2 3
2 1
2 1
1 2
1 2
3 2
3 2
*/