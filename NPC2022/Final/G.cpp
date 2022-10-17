#include <bits/stdc++.h>
using namespace std;

#define pll pair<long long, long long>
#define plll pair<long long, pll>

const long long maxn = 262144;
long long n, m, h, u, v, w;
long long par[maxn], card[maxn], points[maxn], minidx[maxn];
plll edges[maxn];
multiset<pll> ms;
pll queries[2*maxn], ans[2*maxn];

long long getAncestor(long long node){
    long long nxt;
    while(par[node] != node){
        nxt = par[node];
        par[node] = par[nxt];
        node = nxt;
    }
    return node;
}
long long join(long long a, long long b){
    if(card[a] < card[b]){
        long long temp = a; a = b; b = temp;
    }
    par[b] = a;
    card[a] += card[b];
    points[a] += points[b];
    minidx[a] = min(minidx[a], minidx[b]);
    return a;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        par[i] = i;
        card[i] = 1;
        cin >> points[i];
        minidx[i] = i;
        ms.insert({-points[i], minidx[i]});
    }
    for(int i=0; i<m; i++){
        cin >> edges[i].second.first;
        cin >> edges[i].second.second;
        cin >> edges[i].first; edges[i].first *= -1;
    }
    sort(edges, edges+m);
    cin >> h;
    for(int i=0; i<h; i++){
        cin >> queries[i].first; queries[i].first *= -1;
        queries[i].second = i;
    }
    sort(queries, queries+h);
    long long edgeIdx = 0;
    for(int i=0; i<h; i++){
        while(edgeIdx < m && edges[edgeIdx].first <= queries[i].first){
            u = getAncestor(edges[edgeIdx].second.first);
            v = getAncestor(edges[edgeIdx].second.second);
            if(u != v){
                ms.erase({-points[u], minidx[u]});
                ms.erase({-points[v], minidx[v]});
                w = join(u, v);
                ms.insert({-points[w], minidx[w]});
            }
            edgeIdx++;
        }
        ans[queries[i].second] = *(ms.begin());
    }
    for(int i=0; i<h; i++){
        cout << /*ans[i].first << " " <<*/ ans[i].second << endl;
    }
}
