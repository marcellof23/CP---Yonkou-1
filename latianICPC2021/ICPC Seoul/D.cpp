#include <bits/stdc++.h>
using namespace std;

const long long maxn = 1069;
long long n, m;
bool al[maxn][maxn];
long long vis[maxn];
void init_graph(){
    cin >> n >> m;
    long long u, v;
    for(int i=1; i<=n; i++){
        vis[i] = -1;
        for(int j=1; j<=n; j++){
            al[i][j] = (i != j);
        }
    }
    while(m--){
        cin >> u >> v;
        al[u][v] = false;
        al[v][u] = false;
    }
}

vector<pair<long long, long long> > toks;
pair<long long, long long> dfs(long long node){
    //cout << "visit " << node << endl;
    pair<long long, long long> toReturn;
    toReturn = {0, 0};
    if(vis[node] == 0){
        toReturn.first = 1;
    }else{
        toReturn.second = 1;
    }
    for(int i=1; i<=n && toReturn.first >= 0; i++){
        if(al[node][i] && vis[i] < 0){
            vis[i] = (vis[node]+1)%2;
            pair<long long, long long> toAdd;
            toAdd = dfs(i);
            if(toAdd.first < 0){
                toReturn = toAdd;
            }else{
                toReturn.first += toAdd.first;
                toReturn.second += toAdd.second;
            }
        }else if(al[node][i] && vis[i] == vis[node]){
            toReturn = {-1, -1};
        }
    }
    //cout << toReturn.first << " " << toReturn.second << endl;
    return toReturn;
}

bool ks[2][maxn];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	init_graph();
	bool possible = true;
	for(int i=1; i<=n && possible; i++){
        if(vis[i] < 0){
            vis[i] = 0;
            pair<long long, long long> toAdd;
            toAdd = dfs(i);
            //cout << i << " " << toAdd.first << " " << toAdd.second << endl;
            if(toAdd.first < 0){
                possible = false;
            }else{
                toks.push_back(toAdd);
            }
        }
	}
	if(!possible){
        cout << -1 << endl;
        return 0;
	}
	//Knapsack
	for(int i=0; i<maxn; i++){
        ks[0][i] = false;
        ks[1][i] = false;
	}
	ks[0][0] = true;
	for(int i=0; i<toks.size(); i++){
        for(int j=0; j<maxn; j++){
            ks[(i+1)%2][j] = false;
        }
        for(int j=0; j<maxn-toks[i].first; j++){
            if(ks[i%2][j]){
                ks[(i+1)%2][j+toks[i].first] = true;
            }
        }
        for(int j=0; j<maxn-toks[i].second; j++){
            if(ks[i%2][j]){
                ks[(i+1)%2][j+toks[i].second] = true;
            }
        }
	}
	long long sz = toks.size(), ans = 1e18;
	for(int i=0; i<maxn; i++){
        if(ks[sz%2][i]){
            ans = min(abs(2*i - n), ans);
        }
	}
	cout << ans << endl;
}
