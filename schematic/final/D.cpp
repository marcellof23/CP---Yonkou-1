#include <bits/stdc++.h>
using namespace std;

const int maxn = 262144;
int n, q;
vector<int> al[maxn];
int segtree[maxn], range[maxn][2], nodes=0, value[maxn];

void init(){
    int u, v;
    for(int i=1; i<n; i++){
        cin >> u >> v;
        al[u].push_back(v);
        al[v].push_back(u);
        range[i][0] = -1;
    }
    range[n][0] = -1;
}

bool dfs(long long node){
    //cout << "node" << node << endl;
    range[node][0] = nodes;
    nodes++;
    for(int i=0; i<al[node].size(); i++){
        int expand = al[node][i];
        if(range[expand][0]<0){
            dfs(expand);
        }
    }
    range[node][1] = nodes-1;
    // cout << node << " " << range[node][0] << " " << range[node][1] << endl;
}

void build(){
    for(int i=0; i<maxn; i++){
        segtree[maxn+i] = 1;
    }
    for(int i=1; i<=n; i++){
        if(value[i]<0){
            segtree[maxn+range[i][0]] *= -1;
        }
    }
    for(int i=maxn-1; i>0; i--){
        segtree[i] = segtree[2*i]*segtree[2*i+1];
    }
}

void update(int node, int val){
    node += maxn;
    segtree[node] = val;
    node /= 2;
    while(node>0){
        segtree[node] = segtree[2*node]*segtree[2*node+1];
        node /= 2;
    }
}
int query(int lo, int hi){
    lo += maxn; hi += maxn;
    //cout << lo << " " << hi << endl;
    int ret = 1;
    while(lo <= hi){
        if(lo%2 == 1){
            ret *= segtree[lo];
        }
        if(hi%2 == 0){
            ret *= segtree[hi];
        }
        lo = (lo+1)/2;
        hi = (hi-1)/2;
        //cout << lo << " " << hi << endl;
        //cout << "ret" << ret << endl;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> value[i];
    }
    init();
    dfs(1);
    /*
    for(int i=1; i<=n; i++){
        cout << i << " " << range[i][0] << " " << range[i][1] << endl;
    }
    cout << "halo" << endl;
    */
    build();
    /*
    for(int i=1; i<=n; i++){
        cout << i << " " << range[i][0] << " " << range[i][1] << endl;
    }
    */
    int a, b, c;
    cin >> q;
    while(q--){
        cin >> a;
        if(a == 1){
            cin >> b >> c;
            if(c>0){
                update(range[b][0], 1);
            }else{
                update(range[b][0], -1);
            }
        }else{
            cin >> b;
            /*
            for(int i=1; i<=n; i++){
                cout << i << " " << range[i][0] << " " << range[i][1] << endl;
            }
            cout << range[b][0] << " " << range[b][1] << endl;
            */
            if(query(range[b][0], range[b][1])>0){
                cout << "Untung" << endl;
            }else{
                cout << "Rugi" << endl;
            }
        }
    }
}
