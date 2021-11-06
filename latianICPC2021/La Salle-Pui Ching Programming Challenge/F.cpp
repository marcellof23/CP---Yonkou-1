#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin >> n;
    int match[n/2][2], id[n];
    for(int i=0; 2*i<n; i++){
        cin >> match[i][0] >> match[i][1];
        match[i][0]--; match[i][1]--;
        id[match[i][0]] = i;
        id[match[i][1]] = i;
    }
    int p[n], x, y;
    for(int i=0; i<n; i++){
        cin >> p[i] >> x >> y;
    }
    int ans, toadd, cur;
    for(int i=0; i<n; i++){
        p[i] += 3;
        ans = 1 + (p[match[id[i]][0]] > p[i]) + (p[match[id[i]][1]] > p[i]);
        for(int j=0; j<id[i]; j++){
            toadd = 2;
            toadd = min((p[match[j][0]] > p[i]) + (p[match[j][1]]+3 > p[i]), toadd);
            toadd = min((p[match[j][0]]+1 > p[i]) + (p[match[j][1]]+1 > p[i]), toadd);
            toadd = min((p[match[j][0]]+3 > p[i]) + (p[match[j][1]] > p[i]), toadd);
            ans += toadd;
        }
        for(int j=id[i]+1; j<n/2; j++){
            toadd = 2;
            toadd = min((p[match[j][0]] > p[i]) + (p[match[j][1]]+3 > p[i]), toadd);
            toadd = min((p[match[j][0]]+1 > p[i]) + (p[match[j][1]]+1 > p[i]), toadd);
            toadd = min((p[match[j][0]]+3 > p[i]) + (p[match[j][1]] > p[i]), toadd);
            ans += toadd;
        }
        cout << ans << ' ';
        p[i] -= 3;
        ans = (p[match[id[i]][0]]+3 >= p[i]) + (p[match[id[i]][1]]+3 >= p[i]);
        for(int j=0; j<id[i]; j++){
            toadd = 0;
            toadd = max((p[match[j][0]] >= p[i]) + (p[match[j][1]]+3 >= p[i]), toadd);
            toadd = max((p[match[j][0]]+1 >= p[i]) + (p[match[j][1]]+1 >= p[i]), toadd);
            toadd = max((p[match[j][0]]+3 >= p[i]) + (p[match[j][1]] >= p[i]), toadd);
            ans += toadd;
        }
        for(int j=id[i]+1; j<n/2; j++){
            toadd = 0;
            toadd = max((p[match[j][0]] >= p[i]) + (p[match[j][1]]+3 >= p[i]), toadd);
            toadd = max((p[match[j][0]]+1 >= p[i]) + (p[match[j][1]]+1 >= p[i]), toadd);
            toadd = max((p[match[j][0]]+3 >= p[i]) + (p[match[j][1]] >= p[i]), toadd);
            ans += toadd;
        }
        cout << ans << endl;
    }
}
