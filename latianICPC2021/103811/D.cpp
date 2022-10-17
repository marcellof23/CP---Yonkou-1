#include <bits/stdc++.h>

using namespace std;
long long qa, qb, sa, sb, w;
long long n, m;
long long ansa, ansb, donea, doneb;
long long a, b;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> qa >> qb >> sa >> sb >> w;
	cin >> n >> m;
	ansa = (qa+1) * sa + w;
	ansb = (qb+1) * sb + w;
    //cout << ansa << " " << ansb << endl;
	donea = qa * sa;
	while(n--){
        cin >> a;
        if(a <= ansb){
            donea = max(a, donea) + sa;
        }
	}
    //cout << "donea " << donea << endl;
	doneb = qb * sb;
	while(m--){
        cin >> b;
        if(b <= ansa){
            doneb = max(b, doneb) + sb;
        }
	}
	//cout << "doneb " << doneb << endl;
	cout << min(max(ansb, donea) + sa, max(ansa, doneb) + sb) << endl;
}
