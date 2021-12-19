#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair <long long, long long> srt[100069];
multiset <long long> pos, neg;
multiset <long long> :: iterator itr;
long long dif[100069];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    long long n, h;
    cin >> n;
    for(int i=0; i<n; i++){
        dif[i] = 0;
        cin >> h;
        srt[i] = {h, i};
    }
    sort(srt, srt + n);
    long long lo, hi;
    for(int i=n-1; i>=0; i--){
        itr = pos.lower_bound(srt[i].second);
        if(itr != pos.end()){
            hi = (srt[i].second + (*itr) + 1)/2;
        }else{
            hi = n;
        }
        dif[hi] -= 1;
        pos.insert(srt[i].second);
        itr = neg.lower_bound(-srt[i].second);
        if(itr != neg.end()){
            lo = (srt[i].second - (*itr))/2 + 1;
        }else{
            lo = 0;
        }
        dif[lo] += 1;
        neg.insert(-srt[i].second);
        //cout << srt[i].second << ' ' << lo << ' ' << hi << endl;
    }
    long long ans = 0;
    for(int i=0; i<n; i++){
        ans += dif[i];
        cout << ans-1 << ' ';
    }cout << endl;
}
