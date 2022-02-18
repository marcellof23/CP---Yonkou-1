#include <bits/stdc++.h>

using namespace std;

int t, n;
int l, r;
int ans[100069], sz;

int main() {
    cin >> t;
    while(t--){
        cin >> n;
        vector< pair<int, int>  > v[100069];
        for(int i=1; i<=n; i++){
            cin >> l >> r;
            v[l].push_back({r, i});
        }
        multiset<pair<int, int> > ms;
        multiset<pair<int, int> > :: iterator itr;
        sz = 0;
        for(int i=1; i<=n; i++){
            for(int j=0; j<v[i].size(); j++){
                ms.insert(v[i][j]);
            }
            bool dapet = false;
            while(!(ms.empty()) && !dapet){
                itr = ms.begin();
                if((*itr).first >= i){
                    dapet = true;
                    ans[sz] = (*itr).second;
                    sz++;
                }
                ms.erase(itr);
            }
        }
        if(sz<n){
            cout << "impossible" << endl;
        }else{
            for(int i=0; i<n; i++){
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }
}
