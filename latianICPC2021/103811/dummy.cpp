#include <bits/stdc++.h>

using namespace std;
long long qa, qb, sa, sb, w;
long long n, m,
long long ansa, ansb, donea, doneb;
long long a, b;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> qa >> qb >> sa >> sb >> w;
	cin >> n >> m;
	ansa = (qa+1) * sa + w;
	ansb = (qb+1) * sb + w;

	donea = qa * sa;
	while(n--){
        cin >> a;
        if(a <= ansa){
            donea = max(a, donea) + sa;
        }
	}

	doneb = qb * sb;
	while(m--){
        cin >> b;
        if(b <= ansb){
            doneb = max(b, doneb) + sb;
        }
	}
	cout << max(max(ansa, donea) + sa, max(ansb, doneb) + sb) << endl;
}
