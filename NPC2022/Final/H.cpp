#include <bits/stdc++.h>
using namespace std;

#define pll pair<long long, long long>

const long long maxn = 262144;
long long n, m, u, v, w, root;
vector<pll> al[maxn];
bool vis[maxn];
long long ans = 0, nbvis = 1;
pll temp;
multiset<pll> ms;

void insNode(long long node){
    for(int i=0; i<al[node].size(); i++){
        if(!vis[al[node][i].second]){
            ms.insert(al[node][i]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> root >> m;
    while(m--){
        cin >> u >> v >> w;
        al[u].push_back({w, v});
    }
    for(int i=1; i<=n; i++){
        vis[i] = (i==root);
    }
    insNode(root);
    while(!(ms.empty())){
        temp = *(ms.begin());
        ms.erase(temp);
        //cout << temp.first << " " << temp.second << endl;
        if(!vis[temp.second]){
            //cout << temp.second << endl;
            ans += temp.first;
            vis[temp.second] = true;
            nbvis++;
            insNode(temp.second);
        }
    }
    //cout << nbvis << endl;
    if(nbvis < n){
        cout << "No solution" << endl;
    }else{
        cout << ans << endl;
    }
}
