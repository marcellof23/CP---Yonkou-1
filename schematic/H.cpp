#include <bits/stdc++.h>
using namespace std;

const int maxn = 300069;

int mod = 1e9+7, pw2[maxn];
int n, m, q;
vector<int> al[maxn], tree[maxn];
//cycle finding purpose
int par[maxn], color[maxn], curn, cycleID[maxn];

void init(){
    int u, v;
    for(int i=0; i<m; i++){
        cin >> u >> v;
        al[u].push_back(v);
        al[v].push_back(u);
    }
    // initiate color and pangkat
    pw2[0] = 1;
    for(int i=1; i<=n; i++){
        color[i] = -1;
        cycleID[i] = -1;
        pw2[i] = 2*pw2[i-1];
        if(pw2[i] >= mod){
            pw2[i] -= mod;
        }
    }
    //init for dfs
    par[1] = 0;
    curn = n+1;
}

void dfs_cycle(int node){
    // cout << "node" << node << endl;
    color[node] = 0;
    for(int i=0; i<al[node].size(); i++){
        int expand = al[node][i];
        // cout << expand << " " << color[expand] << endl;
        if(expand == par[node]){
            i = i; //continue
        }else if(color[expand] == -1){
            par[expand] = node;
            dfs_cycle(expand);
        }else if(color[expand] == 0){
            //ketemu cycle
            int cur = node;
            // cout << "expand" << expand << " " << node << endl;
            while(cur != expand){
                // cout << cur << endl;
                color[cur] = 1;
                cycleID[cur] = curn;
                cur = par[cur];
            }
            color[cur] = 1;
            cycleID[cur] = curn;
            curn++;
        }
    }
    color[node] = 1;
}
void print_cycleID(){
    for(int i=1; i<=n; i++){
        cout << i << " " << cycleID[i] << endl;
    }
}

void print_tree(){
    for(int i=1; i<curn; i++){
        cout << i << ":" << endl;
        for(int j=0; j<tree[i].size(); j++){
            cout << " " << tree[i][j];
        }
        cout << endl;
    }
}
void build_tree(){
    for(int i=1; i<=n; i++){
        if(cycleID[i]>=0){
            tree[i].push_back(cycleID[i]);
            tree[cycleID[i]].push_back(i);
        }
        for(int j=0; j<al[i].size(); j++){
            int k = al[i][j];
            if(cycleID[i] == cycleID[k] && cycleID[i]>=0){
                i=i;
            }else{
                tree[i].push_back(k);
            }
        }
    }
}

//lca purpose
int lca[20][maxn], nbspecial[20][maxn], depth[maxn];

void dfs_lca(int node){
    for(int i=0; i<tree[node].size(); i++){
        int expand = tree[node][i];
        if(lca[0][expand]<0){
            lca[0][expand] = node;
            depth[expand] = depth[node]+1;
            dfs_lca(expand);
        }
    }
}

void build_lca(){
    for(int i=1; i<curn; i++){
        lca[0][i] = -1;
        if(i>n){
            nbspecial[0][i] = 1;
        }else{
            nbspecial[0][i] = 0;
        }
    }
    lca[0][0] = 0;
    nbspecial[0][0] = 0;
    depth[0] = -1;

    lca[0][1] = 0;
    depth[1] = 0;

    dfs_lca(1);

    for(int i=1; i<20; i++){
        for(int j=0; j<curn; j++){
            int mid = lca[i-1][j];
            lca[i][j] = lca[i-1][mid];
            nbspecial[i][j] = nbspecial[i-1][j] + nbspecial[i-1][mid];
        }
    }
}

void print_lca(){
    for(int i=0; i<5; i++){
        cout << "depth " << i << endl;
        for(int j=0; j<curn; j++){
            cout << lca[i][j] << " : " << nbspecial[i][j] << endl;
        }
    }
}

int query(int x, int y){
    int specials = 0, pw = 0;
    int dif = depth[x] - depth[y];
    while(dif>0){
        if(dif%2){
            specials += nbspecial[pw][x];
            x = lca[pw][x];
        }
        dif /= 2;
        pw++;
    }
    dif = depth[y] - depth[x];
    pw = 0;
    while(dif>0){
        if(dif%2){
            specials += nbspecial[pw][y];
            y = lca[pw][y];
        }
        dif /= 2;
        pw++;
    }
    //at this point x sama y dah sama depthnya
    pw = 19;
    while(pw>=0){
        if(lca[pw][x] != lca[pw][y]){
            specials += nbspecial[pw][x] + nbspecial[pw][y];
            x = lca[pw][x];
            y = lca[pw][y];
        }
        pw--;
    }
    if(x == y){
        specials += nbspecial[0][x];
    }else{
        int z = lca[0][x];
        specials += nbspecial[0][x] + nbspecial[0][y] + nbspecial[0][z];
    }
    return pw2[specials];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    init();
    dfs_cycle(1);
    build_tree();

    build_lca();
    // print_lca();
    cin >> q;
    while(q--){
        int u, v;
        cin >> u >> v;
        cout << query(u, v) << endl;
    }
}
