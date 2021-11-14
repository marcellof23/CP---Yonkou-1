#include <bits/stdc++.h>
using namespace std;

long long n, p[500069], idx;
pair<long long, long long> points[500069];
multiset<long long> ms;
multiset<long long> :: iterator itr;

long long getMaxIdx(long long val){
    long long lo = 0, hi = n;
    while(hi-lo>1){
        long long m = (lo + hi)/2;
        if(p[m] < val){
            lo = m;
        }else{
            hi = m;
        }
    }
    return lo;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> p[i];
    }
    sort(p, p+n);
    // taroh point
    for(int i=0; i<n-1; i++){
        points[i] = {p[i+1]-p[i], i};
    }
    sort(points, points + n-1);
    idx = 0;
    long long hip2, hip2idx, p1idx, p2idx;
    long long ans = -1;
    for(int i=4; i<n-2; i++){
        while(idx < n-1 && points[idx].first < p[i]){
            ms.insert(-points[idx].second);
            idx++;
        }
        hip2 = p[i-1] + p[i-2] + p[i-3] + p[i-4] - p[i];
        hip2idx = getMaxIdx(hip2);
        itr = (ms.lower_bound(-hip2idx));
        if(itr != ms.end() && -(*itr) > i){
            p2idx = -(*itr);
            p1idx = getMaxIdx(p[i] + p[p2idx]);
            ans = max(hip2 + p[i] + p[i] + p[p2idx] + p[p1idx], ans);
        }
    }
    cout << ans << endl;
}
