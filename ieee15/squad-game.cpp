#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+4;
int n;
pair<int, pair<long long, long long>> pts[3][maxn];

long long get_area(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c){
	pair<long long, long long> vec1 = {b.first - a.first, b.second - a.second};
	pair<long long, long long> vec2 = {c.first - a.first, c.second - a.second};
	return abs(vec1.first * vec2.second - vec1.second * vec2.first);
}

void solve_small(){
	vector<vector<int>> ans(3, vector<int>(n));
	for (int i=0; i<n; i++) ans[2][i] = i+1;
	long long min_area = 1e18;
	do{
		do{
			long long cur_area = 0;
			for (int i=0; i<n; i++) cur_area += get_area(pts[0][i].second, pts[1][i].second, pts[2][i].second);
			if (cur_area < min_area){
				for (int i=0; i<n; i++){
					ans[0][i] = pts[0][i].first;
					ans[1][i] = pts[1][i].first;
				}
			}
		} while (next_permutation(pts[1], pts[1]+n));
	} while (next_permutation(pts[0], pts[0]+n));
	for (int i=0; i<n; i++){
		for (int j=0; j<3; j++){
			cout << ans[j][i] << ' ';
		}
		cout << '\n';
	}
}

void solve_random(){
	vector<vector<int>> ans(3, vector<int>(n));
	for (int i=0; i<n; i++) ans[2][i] = i+1;
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int tries = maxn / n * 100;
	long long min_area = 1e18;
	for (int i=0; i<tries; i++){
		shuffle(pts[0], pts[0]+n, rng);
		shuffle(pts[1], pts[1]+n, rng);
		long long cur_area = 0;
		for (int i=0; i<n; i++) cur_area += get_area(pts[0][i].second, pts[1][i].second, pts[2][i].second);
		if (cur_area < min_area){
			for (int i=0; i<n; i++){
				ans[0][i] = pts[0][i].first;
				ans[1][i] = pts[1][i].first;
			}
		}
	}
	for (int i=0; i<n; i++){
		for (int j=0; j<3; j++){
			cout << ans[j][i] << ' ';
		}
		cout << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i=0; i<3; i++){
		for (int j=0; j<n; j++){
			cin >> pts[i][j].second.first >> pts[i][j].second.second;
			pts[i][j].first = j+1;
		}
	}
	if (n <= 7) solve_small();
	else solve_random();
	return 0;
}