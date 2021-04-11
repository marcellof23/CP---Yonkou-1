#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define point pair <double, double>

struct node{
	bool bisa_ignore;
	map<string,node*>adjl;
	node(): bisa_ignore(0), adjl(map<string,node*>()) {}
};

typedef node* pnode;

void dfs1(pnode *u){
	if (((*u)->adjl).empty()) (*u)->bisa_ignore = 1;
	for (auto p : (*u)->adjl){
		dfs1(&p.second);
	}
}

void dfs2(pnode *u){
	if (((*u)->adjl).empty()) return;
	(*u)->bisa_ignore = 1;
	/*
	for (auto p : (*u)->adjl){
		cout << "(" << p.first << "," << p.second->bisa_ignore << ")" << " ";
	}
	cout << "\n";
	*/
	for (auto p : (*u)->adjl){
		dfs2(&p.second);
		if (!((p.second)->bisa_ignore)) (*u)->bisa_ignore = 0;
	}
}

int dfs3(pnode *u){
	if ((*u)->bisa_ignore) return 1;
	int ret = 0;
	for (auto p : (*u)->adjl) ret += dfs3(&p.second);
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		int n, m;
		cin >> n >> m;
		pnode tree = new node;
		for (int i=0; i<n; i++){
			string s;
			cin >> s;
			s += '/';
			int l = 0, r = 0;
			pnode cur_node = tree;
			while (l<(int)s.length()){
				r = l+1;
				while (r<(int)s.length() && s[r]!='/') r++;
				string nama = s.substr(l,r-l);
				if (!(cur_node->adjl).count(nama)) (cur_node->adjl)[nama] = new node;
				l = r+1;
				cur_node = (cur_node->adjl)[nama];
			}
		}
		dfs1(&tree); // ngasih nilai 1 ke bisa_ignore[leaf]
		for (int i=0; i<m; i++){
			string s;
			cin >> s;
			s += '/';
			int l = 0, r = 0;
			pnode cur_node = tree;
			while (l<(int)s.length()){
				r = l+1;
				while (r<(int)s.length() && s[r]!='/') r++;
				string nama = s.substr(l,r-l);
				if (!(cur_node->adjl).count(nama)) (cur_node->adjl)[nama] = new node;
				l = r+1;
				cur_node = (cur_node->adjl)[nama];
			}
		}
		/*
		cout << "tree:\n";
		for (int i=0; i<adjl.size(); i++){
			cout << i << ": ";
			for (int u : adjl[i]) cout << u << " ";
			cout << "\n";
		}
		*/
		dfs2(&tree); // ngisi bisa_ignore
		tree->bisa_ignore = 0;
		int ans = dfs3(&tree); // ngitung jawaban
		// cout << "jawaban = " << ans << "\n";
		cout << ans << "\n";
	}
}

/*
2
3 0
data/train
data/test
model
3 1
data/train
data/test
model
data/sample
*/