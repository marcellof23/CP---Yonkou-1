#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> al[200069];
int color[200069];

void init(){
    int u, v;
    while(m--){
        cin >> u >> v;
        al[u].push_back(v);
        al[v].push_back(u);
    }
    for(int i=1; i<=n; i++){
        color[i] = 0;
    }
}

bool dfs(long long node){
    for(int i=0; i<al[node].size(); i++){
        int expand = al[node][i];
        if(color[expand] == 0){
            color[expand] = -color[node];
            if(!dfs(expand)){
                return false;
            }
        }else if(color[expand] == color[node]){
            return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    init();
    bool ans = true;
    for(int i=1; i<=n && ans; i++){
        if(color[i] == 0){
            color[i] = 1;
            ans = ans && dfs(i);
        }
    }
    if(ans){
        cout << "Tidak" << endl;
    }else{
        cout << "Ya" << endl;
    }
}
