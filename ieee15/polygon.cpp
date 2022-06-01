#include <bits/stdc++.h>
using namespace std;

long long t, n;
long long x[1069], y[1069], z[1069];
long long vx[3], vy[3], vz[3], g; //2 buat dummy
long long cx, cy, cz; //cross
long long a[1069], b[1069], c[2], d[2];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> x[i] >> y[i] >> z[i];
        }
        vx[0] = x[0]-x[n-1];
        vy[0] = y[0]-y[n-1];
        vz[0] = z[0]-z[n-1];
        long long g = __gcd(__gcd(vx[0], vy[0]), vz[0]);
        vx[0] /= g; vy[0] /= g; vz[0] /= g;
        for(int i=1; i<n; i++){
            vx[2] = x[i]-x[i-1];
            vy[2] = y[i]-y[i-1];
            vz[2] = z[i]-z[i-1];
            long long g = __gcd(__gcd(vx[2], vy[2]), vz[2]);
            vx[2] /= g; vy[2] /= g; vz[2] /= g;
            if((vx[0]*vy[2] == vx[2]*vy[0]) && (vx[0]*vz[2] == vx[2]*vz[0]) && (vy[0]*vz[2] == vy[2]*vz[0])){
                n=n; //continue
            }else{
                vx[1] = vx[2];
                vy[1] = vy[2];
                vz[1] = vz[2];
            }
        }
        if(vx[0] == vx[1] && vx[0] == 0){
            vy[0] = 1; vz[0] = 0;
            vy[1] = 0; vz[1] = 1;
        }else if(vy[0] == vy[1] && vy[0] == 0){
            vx[0] = 1; vz[0] = 0;
            vx[1] = 0; vz[1] = 1;
        }else if(vz[0] == vz[1] && vz[0] == 0){
            vy[0] = 1; vx[0] = 0;
            vy[1] = 0; vx[1] = 1;
        }else{
            cx = vy[0]*vz[1] - vy[1]*vz[0];
            cy = vz[0]*vx[1] - vz[1]*vx[0];
            cz = vx[0]*vy[1] - vx[1]*vy[0];
            if(cx == 0){
                if(vy[1] != 0){
                    g = __gcd(vy[1], vz[1]);
                    vx[0] = 0;
                    vy[0] = vy[1]/g;
                    vz[0] = vz[1]/g;
                }else{
                    g = __gcd(vy[0], vz[0]);
                    vx[0] = 0;
                    vy[0] = vy[0]/g;
                    vz[0] = vz[0]/g;
                }
                vx[1] = 1; vy[1] = 0; vz[1] = 0;

            }else{
                g = __gcd(cx,cy);
                vx[0] = -cy/g;
                vy[0] = cx/g;
                vz[0] = 0;
                g = __gcd(cx, cz);
                vx[1] = -cz/g;
                vy[1] = 0;
                vz[1] = cx/g;
            }

        }
        //cout << vx[0] << ' ' << vy[0] << ' ' << vz[0] << endl;
        //cout << vx[1] << ' ' << vy[1] << ' ' << vz[1] << endl;
        // at this point dah dapet 2 vektor ga sejajar yg relatif prima?
        a[0] = 0;
        b[0] = 0;
        for(int i=1; i<n; i++){
            x[i] -= x[0];
            y[i] -= y[0];
            z[i] -= z[0];
            //cout << vx[0]*vy[1] - vx[1]*vy[0] << endl;
            //cout << vy[0]*vz[1] - vz[0]*vy[1] << endl;
            //cout << vx[0]*vz[1] - vz[0]*vx[1] << endl;
            if(vz[0]*vy[1] != vz[1]*vy[0]){
                //y sama z
                a[i] = (y[i]*vz[1] - z[i]*vy[1])/(vy[0]*vz[1] - vz[0]*vy[1]);
                b[i] = (y[i]*vz[0] - z[i]*vy[0])/(vy[1]*vz[0] - vz[1]*vy[0]);
            }else if(vy[0]*vx[1] != vx[0]*vy[1]){
                a[i] = (y[i]*vx[1] - x[i]*vy[1])/(vy[0]*vx[1] - vx[0]*vy[1]);
                b[i] = (y[i]*vx[0] - x[i]*vy[0])/(vy[1]*vx[0] - vx[1]*vy[0]);
            }else{
                //cout << "halo" << endl;
                a[i] = (x[i]*vz[1] - z[i]*vx[1])/(vx[0]*vz[1] - vz[0]*vx[1]);
                b[i] = (x[i]*vz[0] - z[i]*vx[0])/(vx[1]*vz[0] - vz[1]*vx[0]);
            }
            // cout 2 dimensi
            // cout << a[i] << " " << b[i] << endl;
        }
        long long sum = 0, border = 0;
        for (int i=0; i<n; i++){
			sum += a[i] * b[(i+1)%n] - b[i] * a[(i+1)%n];
			border += __gcd(abs(a[i] - a[(i+1)%n]), abs(b[i] - b[(i+1)%n]));
		}
		sum = abs(sum);
		long long ans = (sum - border)/2 + 1;
		cout << ans << '\n';
    }
}