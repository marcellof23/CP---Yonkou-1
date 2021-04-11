#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int tc;
	cin >> tc;
	while (tc--){
		double n, v1, p1, p2, v2;
		cin >> n >> p1 >> v1 >> p2 >> v2;
		if (p1>p2){
			swap(p1,p2);
			swap(v1,v2);
		}
		double l1, r1;
		double ans[9];
		// p1 kiri, p1 kiri
		// cout << "yey\n";
		l1 = p1, r1 = p2;
		while (fabs(r1-l1)>1e-6){
			double l2 = l1 + (r1-l1)/3;
			double r2 = r1 - (r1-l1)/3;
			double tmpl = max((2*p1)/v1 + (l2-p1)/v1, (2*(p2-l2))/v2 + (n-p2)/v2);
			double tmpr = max((2*p1)/v1 + (r2-p1)/v1, (2*(p2-r2))/v2 + (n-p2)/v2);
			if (tmpl<tmpr) r1 = r2;
			else l1 = l2;
		}
		ans[0] = max((2*p1)/v1 + (l1-p1)/v1, (2*(p2-l1))/v2 + (n-p2)/v2);
		// p1 kiri, p2 kanan
		l1 = p1, r1 = p2;
		while (fabs(r1-l1)>1e-6){
			double l2 = l1 + (r1-l1)/3;
			double r2 = r1 - (r1-l1)/3;
			double tmpl = max((2*p1)/v1 + (l2-p1)/v1, (p2-l2)/v2 + (2*(n-p2))/v2);
			double tmpr = max((2*p1)/v1 + (r2-p1)/v1, (p2-r2)/v2 + (2*(n-p2))/v2);
			if (tmpl<tmpr) r1 = r2;
			else l1 = l2;
		}
		ans[1] = max((2*p1)/v1 + (l1-p1)/v1, (p2-l1)/v2 + (2*(n-p2))/v2);;
		// p1 kanan, p2 kiri
		l1 = p1, r1 = p2;
		while (fabs(r1-l1)>1e-6){
			double l2 = l1 + (r1-l1)/3;
			double r2 = r1 - (r1-l1)/3;
			double tmpl = max(p1/v1 + 2*(l2-p1)/v1, 2*(p2-l2)/v2 + (n-p2)/v2);
			double tmpr = max(p1/v1 + 2*(r2-p1)/v1, 2*(p2-r2)/v2 + (n-p2)/v2);
			if (tmpl<tmpr) r1 = r2;
			else l1 = l2;
		}
		ans[2] = max(p1/v1 + 2*(l1-p1)/v1, 2*(p2-l1)/v2 + (n-p2)/v2);
		// p1 kanan, p2 kanan
		l1 = p1, r1 = p2;
		while (fabs(r1-l1)>1e-6){
			double l2 = l1 + (r1-l1)/3;
			double r2 = r1 - (r1-l1)/3;
			double tmpl = max(p1/v1 + 2*(l2-p1)/v1, (p2-l2)/v2 + (2*(n-p2))/v2);
			double tmpr = max(p1/v1 + 2*(r2-p1)/v1, (p2-r2)/v2 + (2*(n-p2))/v2);
			if (tmpl<tmpr) r1 = r2;
			else l1 = l2;
		}
		ans[3] = max(p1/v1 + 2*(l1-p1)/v1, (p2-l1)/v2 + (2*(n-p2))/v2);
		// p1 sendiri
		ans[4] = min((p1+n)/v1,((n-p1)+n)/v1);
		// p2 sendiri
		ans[5] = min((p2+n)/v2,((n-p2)+n)/v2);
		// p1 nggak bolak-balik
		ans[6] = max(p1/v1,min(2*(p2-p1)/v2+(n-p2)/v2,(p2-p1)/v2+2*(n-p2)/v2));
		// p2 nggak bolak-balik
		ans[7] = max((n-p2)/v2,min(2*p1/v1+(p2-p1)/v1,p1/v1+2*(p2-p1)/v1));
		// p1 ke kanan, p2 ke kiri
		ans[8] = (n-p1)/v1 + p2/v2;
		double final_ans = 1e17;
		for (int i=0; i<9; i++) final_ans = min(final_ans,ans[i]);
		cout << fixed << setprecision(12) << final_ans << "\n";
	}
}