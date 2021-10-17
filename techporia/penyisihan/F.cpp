#include <bits/stdc++.h>
using namespace std;

long long n, q;
const long long maxn = 131072;
long long segtree[2*maxn], h[maxn];

void build(){
    for(int i=1; i<2*maxn; i++){
        segtree[i] = 0;
    }
}

void update(long long node, long long val){
    node += maxn;
    while(node>0){
        segtree[node] += val;
        node /= 2;
    }
}

long long query(long long l, long long r){
    l += maxn;
    r += maxn;
    long long ret = 0;
    while(l<=r){
        if(l%2==1){ret += segtree[l];}
        if(r%2==0){ret += segtree[r];}
        l = (l+1)/2;
        r = (r-1)/2;
    }
    return ret;
}

set <long long> chu, chuinv;
long long chustack[maxn], top;
long long ans;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long t;
    cin >> t;
    while(t--){
        build();
        cin >> n >> q;
        top = 0;
        for(int i=0; i<n; i++){
            cin >> h[i];
            // Itung dhu stack
            while(top>0 && h[chustack[top-1]] < h[i]){top--;}
            chustack[top] = i;
            top++;
            // Update segtree
            update(i, h[i]);
        }
        //taroh semua dalam set
        chu.clear();
        chuinv.clear();
        for(int i=0; i<top; i++){
            //cout << chustack[i] << endl;
            chu.insert(chustack[i]);
            chuinv.insert(-chustack[i]);
        }
        /*
        for(set<long long> :: iterator itr = chuinv.begin(); itr != chuinv.end(); itr++){
            cout << *itr << endl;
        }
        */
        //itung ans awal
        ans = 0;

        for(int i=1; i<top; i++){
            ans += min(h[chustack[i-1]], h[chustack[i]])*(chustack[i]-chustack[i-1]-1) - query(chustack[i-1]+1, chustack[i]-1);
        }


        char typ;
        long long node, val, l, r;
        while(q--){
            cin >> typ;
            if(typ == 'P'){
                cout << ans << endl;
            }else{
                cin >> node >> val;
                node--;
                if(chu.count(node)>0){
                    //udh masuk chu masbro
                    //cout << "ada chu " << node << endl;
                    /*
                    for(set<long long> :: iterator itr = chuinv.begin(); itr != chuinv.end(); itr++){
                        cout << *itr << endl;
                    }
                    */
                    if(node>0){
                        l = *(chuinv.upper_bound(-node));
                        l *= -1;
                        // cout << "l " << l << " " << h[l] << " " << h[node] << endl;
                        // cout << ans << endl;
                        if(h[l] > h[node]){
                            ans += min(h[l] - h[node], val) * (node-l-1);
                        }
                        // cout << ans << endl;
                    }
                    if(node<n-1){
                        r = *(chu.upper_bound(node));
                        if(h[r] > h[node]){
                            ans += min(h[r] - h[node], val) * (r-node-1);
                        }
                    }
                }else{
                    // belom masuk chu, pasti 0<x<n-1
                    l = *(chuinv.upper_bound(-node));
                    l *= -1;
                    r = *(chu.upper_bound(node));
                    if(h[node] < min(h[l], h[r])){
                        ans -= val;
                    }else{
                        chu.insert(node);
                        chuinv.insert(-node);
                        ans -= min(h[l], h[r])*(r-l-1) - query(l+1, r-1);
                        ans += min(h[l], h[node])*(node-l-1) - query(l+1, node-1);
                        ans += min(h[node], h[r])*(r-node-1) - query(node+1, r-1);
                    }
                }
                update(node, val);
                h[node] += val;
                // cout << ans << endl;
            }
        }
    }
}
