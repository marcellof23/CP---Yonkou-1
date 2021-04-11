#include <bits/stdc++.h>
using namespace std;

struct isi{
	int val, pos, num; // num is num on a or query
	bool active;
	isi(){}
	isi(int _val, int _pos, int _num, bool _active) : val(_val), pos(_pos), num(_num), active(_active){}
	bool operator<(isi &other){
		return this->val < other.val;
	}
};

const int maxn = 1e5+4, maxq = 1e5+4;
int n, q;
int a[maxn], sorted_a[maxn];
int maxst[4*maxn], minst[4*maxn];
pair<int, int> lrst[4*(maxn+maxq)];
isi elements[maxn+maxq];
pair<int, int> queries[maxq];
map<int, int> rightmost, leftmost;
int idx_di_pos_ini[maxn];
int ans;
multiset<int> mst;
map<int, int> tambal;

void build_maxminst(int l, int r, int v){
	if (l == r) maxst[v] = minst[v] = a[l];
	else{
		int mid = (l+r)/2;
		build_maxminst(l, mid, v*2);
		build_maxminst(mid+1, r, v*2+1);
		maxst[v] = max(maxst[v*2], maxst[v*2+1]);
		minst[v] = min(minst[v*2], minst[v*2+1]);
	}
}

int get_mx(int l, int r, int v, int lb, int rb){
	if (lb > rb || r < lb || l > rb) return -1e9;
	if (l >= lb && r <= rb) return maxst[v];
	int mid = (l+r)/2;
	return max(get_mx(l, mid, v*2, lb, rb), get_mx(mid+1, r, v*2+1, lb, rb));
}

int get_mn(int l, int r, int v, int lb, int rb){
	if (lb > rb || r < lb || l > rb) return 1e9;
	if (l >= lb && r <= rb) return minst[v];
	int mid = (l+r)/2;
	return min(get_mn(l, mid, v*2, lb, rb), get_mn(mid+1, r, v*2+1, lb, rb));
}

void update_maxminst(int l, int r, int v, int pos, int val){
	if (l == r) maxst[v] = minst[v] = val;
	else{
		int mid = (l+r)/2;
		if (pos <= mid) update_maxminst(l, mid, v*2, pos, val);
		else update_maxminst(mid+1, r, v*2+1, pos, val);
		maxst[v] = max(maxst[v*2], maxst[v*2+1]);
		minst[v] = min(minst[v*2], minst[v*2+1]);
	}
}

void build_lrst(int l, int r, int v){
	if (l == r){
		if (!elements[l].active) lrst[v] = pair<int, int>(1e9, -1e9);
		else lrst[v] = pair<int, int>(elements[l].pos, elements[l].pos);
	}
	else{
		int mid = (l+r)/2;
		build_lrst(l, mid, v*2);
		build_lrst(mid+1, r, v*2+1);
		lrst[v].first = min(lrst[v*2].first, lrst[v*2+1].first);
		lrst[v].second = max(lrst[v*2].second, lrst[v*2+1].second);
	}
}

pair<int, int> get_lr(int l, int r, int v, int lb, int rb){
	if (lb > rb || r < lb || l > rb) return pair<int, int>(1e9, -1e9);
	if (l >= lb && r <= rb) return lrst[v];
	int mid = (l+r)/2;
	pair<int, int> tmpl = get_lr(l, mid, v*2, lb, rb);
	pair<int, int> tmpr = get_lr(mid+1, r, v*2+1, lb, rb);
	return pair<int, int>(min(tmpl.first, tmpr.first), max(tmpl.second, tmpr.second));
}

void update_lrst(int l, int r, int v, int pos, bool active){
	if (l == r){
		elements[l].active = active;
		if (!elements[l].active) lrst[v] = pair<int, int>(1e9, -1e9);
		else lrst[v] = pair<int, int>(elements[l].pos, elements[l].pos);
	}
	else{
		int mid = (l+r)/2;
		if (pos <= mid) update_lrst(l, mid, v*2, pos, active);
		else update_lrst(mid+1, r, v*2+1, pos, active);
		lrst[v].first = min(lrst[v*2].first, lrst[v*2+1].first);
		lrst[v].second = max(lrst[v*2].second, lrst[v*2+1].second);
	}
}

void debug_elements(){
	for (int i=0; i<n+q-1; i++){
		cout << elements[i].val << " " << elements[i].pos << " " << elements[i].num << " " << elements[i].active << "\n" ;
	}
	cout << "\n";
	while (1){
		int pos;
		cin >> pos;
		auto tmp = get_lr(0, n+q-1, 1, 0, pos-1);
		cout << tmp.first << " " << tmp.second << "\n";
	}
}

int main(){
	// ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	for (int i=0; i<n; i++){
		cin >> a[i];
		sorted_a[i] = a[i];
		elements[i] = isi(a[i], i, i, 1);
	}
	for (int i=0; i<q; i++){
		int x, y;
		cin >> x >> y;
		queries[i] = pair<int, int>(x, y);
		elements[i+n] = isi(y, x-1, n+i, 0);
	}
	sort(elements, elements+n+q);
	reverse(elements, elements+n+q);
	sort(sorted_a, sorted_a+n);
	reverse(sorted_a, sorted_a+n);
	build_maxminst(0, n-1, 1);
	build_lrst(0, n+q-1, 1);
	// build rightmost
	for (int i=0; i<n+q; i++){
		rightmost[elements[i].val] = i;
	}
	for (int i=n+q-1; i>=0; i--){
		leftmost[elements[i].val] = i;
	}
	for (int i=0; i<n+q-1; i++) tambal[elements[i].num] = i;
	// cout << "rightmost 3  = " << rightmost[3] << "\n";
	// build idx converter
	for (int i=0; i<n+q; i++){
		if (elements[i].num < n) idx_di_pos_ini[elements[i].num] = i;
	}
	// get initial ans
	ans = 0;
	int active_rightmost = 0;
	for (int i=0; i<n; i++){
		mst.insert(sorted_a[i]);
		if (i > 0 && sorted_a[i] == sorted_a[i-1]) continue;
		active_rightmost = max(active_rightmost, rightmost[sorted_a[i]]);
		// cout << "rightmost = " << active_rightmost << "\n";
		pair<int, int> activeseg = get_lr(0, n+q-1, 1, 0, active_rightmost); // boros time sih tapi yaudahlah
		// cout << "seg = " << activeseg.first << " " << activeseg.second << "\n";
		int mn = get_mn(0, n-1, 1, activeseg.first, activeseg.second);
		int mx = max(get_mx(0, n-1, 1, 0, activeseg.first-1), get_mx(0, n-1, 1, activeseg.second+1, n-1));
		mx = max(mx, 0);
		// cout << mn << " " << mx << "\n";
		ans += max(0, mn-mx); // +1 gak ya
	}
	//cout << "init ans = " << ans << "\n";
	// debug_elements();
	// queries
	for (int i=0; i<q; i++){
		int x = queries[i].first-1, y = queries[i].second;
		// kurangi jawaban
		{
		pair<int, int> activeseg = get_lr(0, n+q-1, 1, 0, rightmost[a[x]]); // boros time sih tapi yaudahlah
		int mn = get_mn(0, n-1, 1, activeseg.first, activeseg.second);
		int mx = max(get_mx(0, n-1, 1, 0, activeseg.first-1), get_mx(0, n-1, 1, activeseg.second+1, n-1));
		mx = max(mx, 0);
		ans -= max(0, mn-mx-1); // +1 gak ya
		}
		mst.erase(mst.find(a[x]));
		if (mst.count(y)){
		pair<int, int> activeseg = get_lr(0, n+q-1, 1, 0, rightmost[y]); // boros time sih tapi yaudahlah
		int mn = get_mn(0, n-1, 1, activeseg.first, activeseg.second);
		int mx = max(get_mx(0, n-1, 1, 0, activeseg.first-1), get_mx(0, n-1, 1, activeseg.second+1, n-1));
		mx = max(mx, 0);
		ans -= max(0, mn-mx-1); // +1 gak ya
		}
		//}
		// update maxmin st
		update_maxminst(0, n-1, 1, x, y);
		// tambahin lagi jawaban
		// jawaban ditambah kalo x ada di ujung
		// pair<int, int> tmp = get_lr(0, n+q-1, 1, 0, rightmost[y]);
		// 	pair<int, int> activeseg = tmp; // boros time sih tapi yaudahlah
		// 	activeseg.first = min(activeseg.first, x);
		// 	activeseg.second = max(activeseg.second, x);
		// 	cout << "seg = " << activeseg.first << " " << activeseg.second << "\n";
		// 	int mn = get_mn(0, n-1, 1, activeseg.first, activeseg.second);
		// 	int mx = max(get_mx(0, n-1, 1, 0, activeseg.first-1), get_mx(0, n-1, 1, activeseg.second+1, n-1));
		// 	mx = max(mx, 0);
		// 	ans += max(0, mn-mx); // +1 gak ya
		// update lr st
		update_lrst(0, n+q-1, 1, idx_di_pos_ini[x], 0);
		idx_di_pos_ini[x] = tambal[n+i];
		update_lrst(0, n+q-1, 1, idx_di_pos_ini[x], 1);
		mst.insert(y);
		if (mst.count(a[x])){
		pair<int, int> activeseg = get_lr(0, n+q-1, 1, 0, rightmost[a[x]]); // boros time sih tapi yaudahlah
		int mn = get_mn(0, n-1, 1, activeseg.first, activeseg.second);
		int mx = max(get_mx(0, n-1, 1, 0, activeseg.first-1), get_mx(0, n-1, 1, activeseg.second+1, n-1));
		mx = max(mx, 0);
		ans += max(0, mn-mx); // +1 gak ya
		}
		{
		pair<int, int> activeseg = get_lr(0, n+q-1, 1, 0, rightmost[y]); // boros time sih tapi yaudahlah
		// out << activeseg.first << " " << activeseg.second << " " << y << "\n";
		int mn = get_mn(0, n-1, 1, activeseg.first, activeseg.second);
		int mx = max(get_mx(0, n-1, 1, 0, activeseg.first-1), get_mx(0, n-1, 1, activeseg.second+1, n-1));
		mx = max(mx, 0);
		// cout << mn << " " << mx << "\n";
		ans += max(0, mn-mx); // +1 gak ya
		}
		a[x] = y;
		cout << ans-1 << "\n";
	}
}