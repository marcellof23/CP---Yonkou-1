#include <bits/stdc++.h>
using namespace std;

const long long maxn = 1000069;
long long n, arr[2][maxn], dif[3][maxn];
pair<long long, long long> sorter[maxn];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[0][i];
    }
    sort(arr[0], arr[0] + n);
    for(int i=0; i<n; i++){
        cin >> arr[1][i];
    }
    sort(arr[1], arr[1] + n);

    for(int i=0; i<n-1; i++){
        dif[0][i] = abs(arr[1][i] - arr[0][i]);
        sorter[i] = {dif[0][i], i};
        dif[1][i] = abs(arr[1][i+1] - arr[0][i]);
        dif[2][i] = abs(arr[1][i] - arr[0][i+1]);
    }
    dif[0][n-1] = abs(arr[1][n-1] - arr[0][n-1]);
    sorter[n-1] = {dif[0][n-1], n-1};
    sort(sorter, sorter + n);

    long long ans = arr[0][sorter[n-1].second];
    long long comp = sorter[n-2].first;

    long long l, r, tl, tr, tomax;
    l = sorter[n-1].second;
    r = sorter[n-1].second;
    tomax = 0;
    for(int i=n-2; i>=0; i--){
        while(l > sorter[i].second){
            l--;
            tomax = max(tomax, dif[1][l]);
        }
        while(r < sorter[i].second){
            tomax = max(tomax, dif[1][r]);
            r++;
        }
        long long tocomp = tomax;
        if(i > 0){
            tocomp = max(tocomp, sorter[i-1].first);
        }
        if(tocomp < comp){
            comp = tocomp;
            ans = arr[0][r];
        }
    }

    l = sorter[n-1].second;
    r = sorter[n-1].second;
    tomax = 0;
    for(int i=n-2; i>=0; i--){
        while(l > sorter[i].second){
            l--;
            tomax = max(tomax, dif[2][l]);
        }
        while(r < sorter[i].second){
            tomax = max(tomax, dif[2][r]);
            r++;
        }
        long long tocomp = tomax;
        if(i > 0){
            tocomp = max(tocomp, sorter[i-1].first);
        }
        if(tocomp < comp){
            comp = tocomp;
            ans = arr[0][l];
        }
    }
    cout << ans << endl;
}
