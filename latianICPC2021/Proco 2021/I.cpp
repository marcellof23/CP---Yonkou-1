#include <bits/stdc++.h>
using namespace std;
#define ll long long

long long n, a, avg, srt[500069];
long long cur, ans;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n;
    cin >> a;
    srt[0] = a;
    for(int i=1; i<n; i++){
        cin >> a;
        srt[i] = srt[i-1] + a;
    }
    avg = srt[n-1]/n;
    for(int i=0; i<n; i++){
        srt[i] -= (i+1)*avg;
        //cout << srt[i] << endl;
    }
    sort(srt, srt + n);
    ans = 0;
    cur = 1;
    for(int i=1; i<n; i++){
        if(srt[i] == srt[i-1]){
            cur++;
        }else{
            ans = max(cur, ans);
            cur = 1;
        }
    }
    ans = max(cur, ans);
    cout << n-ans << endl;
}
