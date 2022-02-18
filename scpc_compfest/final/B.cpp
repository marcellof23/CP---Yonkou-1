#include <bits/stdc++.h>
using namespace std;

int n, k;
//polar
const double pi = acos(-1);
double x, y, newx[100069], newy[100069];
//binser
double mbin, lbin, rbin, lrange[200069], rrange[200069], radrange;
int lidx, ridx, ans, cur, ranges;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> x >> y;
        newx[i] = atan2(x, y);
        newy[i] = sqrt(x*x + y*y);
    }
    /*
    for(int i=0; i<n; i++){
        cout << newx[i] << " " << newy[i] << endl;
    }
    */
    lbin = 0; rbin = 240000;
    //binser 40 kali
    for(int i=0; i<40; i++){
        mbin = (lbin + rbin)/2.0;
        ranges = 0;
        for(int j=0; j<n; j++){
            if(newy[j] <= mbin){
                radrange = acos(newy[j]/mbin);
                // cek kalau range kepotong
                if(newx[j] - radrange < -pi){
                    lrange[ranges] = newx[j] - radrange + pi*2.0;
                    rrange[ranges] = pi;
                    ranges++;
                }
                if(newx[j] + radrange > pi){
                    lrange[ranges] = -pi;
                    rrange[ranges] = newx[j] + radrange - pi*2.0;
                    ranges++;
                }
                //taroh main range
                lrange[ranges] = max(-pi, newx[j] - radrange);
                rrange[ranges] = min(pi, newx[j] + radrange);
                ranges++;
            }
        }
        sort(lrange, lrange + ranges);
        sort(rrange, rrange + ranges);
        lidx = 0; ridx = 0; ans = 0; cur = 0;
        while(ridx < ranges){
            if(lidx<ranges && lrange[lidx]<=rrange[ridx]){
                lidx++; cur++;
                ans = max(ans, cur);
            }else{
                ridx++; cur--;
            }
        }
        if(ans<k){
            lbin = mbin;
        }else{
            rbin = mbin;
        }
    }
    cout << fixed << setprecision(9) << rbin/2.0 << endl;
	return 0;
}
