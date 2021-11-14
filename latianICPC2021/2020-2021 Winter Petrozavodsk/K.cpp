#include <bits/stdc++.h>
using namespace std;

const long long maxn = 300069;
long long ans[maxn], n, m, l, r;
pair<pair<long long, long long>, long long> sorter[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> l >> r;
        sorter[i] = {{l, r}, i};
        ans[i] = 0;
    }
    sort(sorter, sorter + n);
    for(int i=0; i<n; i++){
        if(i<n-m){
            l = sorter[i].first.first;
            r = sorter[i].first.second;
            sorter[i].first = {r, l};
        }else{
            ans[sorter[i].second] = 1 + i - (n-m);
        }
    }
    sort(sorter, sorter + (n-m));
    long long idx = 0;
    for(int i=0; i<n-m; i++){
        r = sorter[i].first.first;
        l = sorter[n-m+idx].first.first;
        while(idx < m && l <= r){
            idx++;
            l = sorter[n-m+idx].first.first;
        }
        if(idx < m){
            idx++;
            ans[sorter[i].second] = idx;
        }
    }
    for(int i=0; i<n; i++){
        cout << ans[i] << ' ';
    }cout << endl;
}
