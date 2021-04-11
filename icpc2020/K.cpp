#include <bits/stdc++.h>
using namespace std;

vector <long long> child[100069];
long long nbchild[100069][20];
long long fenwig[262144], curfix, range[100069][2];

void dfs(long long a){
	curfix++;
	range[a][0] = curfix;
	for(int i=0; i<child[a].size(); i++){
		dfs(child[a][i]);
	}
	range[a][1] = curfix;
}

void addfenwig(long long val, long long node){
	long long cur = range[node][0];
	while(cur>0){
		fenwig[cur] += val;
		cur /= 2;
	}
	fenwig[cur] += val;
}

long long sumrange(long long a, long long b){
	if(a>b){
		return 0;
	}else if(a==b){
		return fenwig[a];
	}else{
		long long result = 0;
		if(a%2==1){
			result += fenwig[a];
		}
		if(b%2==0){
			result += fenwig[b];
		}
		result += sumrange((a+1)/2, (b-1)/2);
		return result;
	}
}

int main(){
	long long n, Q;
	cin >> n >> Q;
	long long par[n+1];
	par[1] = 0;
	for(int i=2; i<=n; i++){
		cin >> par[i];
		child[par[i]].push_back(i);
	}
	for(int i=1; i<=n; i++){
		nbchild[i][0] = 1; //diri sendiri
	}
	for(int j=1; j<20; j++){
		for(int i=1; i<=n; i++){
			nbchild[i][j] = 0;
			for(int k=0; k<child[i].size(); k++){
				nbchild[i][j] += nbchild[child[i][k]][j-1];
			}
		}
	}
	curfix = 131071;
	dfs(1);
	for(int i=0; i<262144; i++){
		fenwig[i] = 0;
	}
	long long X, Y, Z, K, add;
	while(Q>0){
		cin >> Z;
		if(Z==1){
			cin >> X >> Y >> K;
			if(K==1){
				add = Y*(range[X][1] - range[X][0]+1);
			}else{
				add = 0;
				for(int j=0; j<20; j++){
					add += Y*nbchild[X][j];
					Y /= K;
				}
			}
			addfenwig(add, X);
		}else{
			cin >> X;
			cout << sumrange(range[X][0], range[X][1]) << endl;
		}
		Q--;
	}
	return 0;
}