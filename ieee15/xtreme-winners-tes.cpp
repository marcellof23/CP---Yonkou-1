#include <bits/stdc++.h>
using namespace std;

bool valid(vector<long long> &a, long long mod){
	for (int i=1; i<14; i++){
		if (a[i] != (a[i-1]+1)%mod) return false;
	}
	return true;
}

const long long maxmul = 1e6;

int main(){
	// ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("xtreme-winners-tes.txt", "w", stdout);
	vector<string> coba = {
		"Team 1",
		"Knapsackers@UNT",
		"MoraSeekers",
		"SurpriseTeam",
		"CuSAT",
		"DongskarPedongi",
		"cofrades",
		"viRUs",
		"TeamName",
		"TeamEPFL1",
		"whatevs",
		"WildCornAncestors",
		"TheCornInTheFields",
		"Aurora"
	};
	for (long long mul=1; mul<=maxmul; mul++){
		for (long long mod=14; mod<=2*mul; mod++){
			vector<long long> a;
			for (string s : coba) a.push_back((s[3]^s[4]) * mul % mod);
			if (valid(a, mod)){
				cout << "a: ";
				for (long long x : a) cout << x << ' ';
				cout << '\n';
				cout << "mul= " << mul << ' ' << "mod=" << mod << '\n';
			}
		}
	}
	return 0;
}