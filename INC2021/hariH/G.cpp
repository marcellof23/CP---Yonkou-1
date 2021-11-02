#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<int> > adj, adj_rev;
vector<bool> used;
vector<int> order, component;

void dfs1(int v) {
    used[v] = true;

    for (int i=0; i<adj[v].size(); i++){
        int u = adj[v][i];
        if (!used[u]){
            dfs1(u);
        }
    }

    order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    component.push_back(v);

    for (int i=0; i<adj_rev[v].size(); i++){
        int u = adj_rev[v][i];
        if (!used[u]){
            dfs2(u);
        }
    }
}

vector<int> tidx;
bool adjm[510][510];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, m, t;
    cin >> n >> m >> t;
    tidx.resize(t);

    for(int i=0; i<t; i++){
        cin >> tidx[i];
        tidx[i]--;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            adjm[i][j] = (i==j);
        }
    }
    while(m--){
        int a, b;
        cin >> a >> b;
        a--; b--;
        adjm[a][b] = true;
    }
    //floyd warshal
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                adjm[i][j] = adjm[i][j] || (adjm[i][k] && adjm[k][j]);
            }
        }
    }
    /*
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << adjm[i][j] << ' ';
        }cout << endl;
    }*/
    n = t;
    adj.resize(n);
    adj_rev.resize(n);
    for(int i=0; i<t; i++){
        for(int j=0; j<t; j++){
            int a=tidx[i], b=tidx[j];
            if(a!=b && adjm[a][b]){
                adj[i].push_back(j);
                adj_rev[j].push_back(i);
            }
        }
    }


    used.assign(n, false);
    for (int i = 0; i < n; i++){
        if (!used[i]){
            dfs1(i);
        }
    }

    used.assign(n, false);
    reverse(order.begin(), order.end());

    vector<int> roots(n, 0);
    vector<int> root_nodes;
    vector<vector<int> > adj_scc(n);

    for (int i=0; i<order.size(); i++){
        int v = order[i];
        if (!used[v]) {
            dfs2 (v);

            int root = component.front();
            for (int i=0; i<component.size(); i++){
                int u = component[i];
                roots[u] = root;
            }
            root_nodes.push_back(root);

            component.clear();
        }
    }

    int indeg[n];
    for(int i=0; i<n; i++){
        indeg[i] = 0;
    }
    for (int v = 0; v < n; v++){
        for (int i=0; i<adj[v].size(); i++) {
            int u = adj[v][i];
            int root_v = roots[v],
                root_u = roots[u];

            if (root_u != root_v){
                adj_scc[root_v].push_back(root_u);
                indeg[root_u]++;
            }
        }
    }

    for(int i=0; i<root_nodes.size(); i++){

        cout << root_nodes[i] << ':';
        for(int j=0; j<adj_scc[root_nodes[i]].size(); j++){
            cout << ' ' << adj_scc[root_nodes[i]][j];
        }
        cout << endl;
        /*
        if(indeg[root_nodes[i]] == 0){
            q.push(root_nodes[i]);
        }
        */
    }

}
