#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    multiset<pair<int, int> > pos, neg;
    multiset<pair<int, int> > :: iterator itr1, itr2;
    long long n, d, q;
    cin >> n;
    pos.insert({0,0});
    neg.insert({0,0});
    for(int i=1; i<=n; i++){
        cin >> d;
        pos.insert({d,i});
        neg.insert({-d,i});
    }
    long long x, y, ans;
    cin >> q;
    while(q--){
        cin >> x >> y;
        d = y-x;
        itr1 = pos.lower_bound({d,0});
        itr2 = neg.lower_bound({-d,0});
        if(itr1 != pos.end() && itr1->first < y){
            if(itr1->first - d > itr2->first + d){
                ans = itr2->second;
            }else if(itr1->first - d < itr2->first + d){
                ans = itr1->second;
            }else{
                ans = min(itr1->second, itr2->second);
            }
        }else{
            ans = itr2->second;
        }
        cout << ans % (n+1) << endl;
    }
}
