#include <bits/stdc++.h>
using namespace std;
<<<<<<< HEAD

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s, ans;
    long long t, n, r, mx=0, nb=0;
    cin >> t;
    while(t--){
        cin >> s >> n >> r;
        if(r>mx){
            ans = s;
            mx = r;
            nb = 1;
        }else if(r == mx){
            nb++;
        }
    }
    if(nb>1){
        cout << "SERI" << endl;
    }else{
        cout << ans << endl;
    }
=======
#define ll long long

int main()
{
  int T;
  cin >> T;
  string S[T];
  int N[T], R[T];
  pair<double, int> p[T];
  for (int i = 0; i < T; i++)
  {
    cin >> S[i] >> N[i] >> R[i];
    double juring_part = (((double)180 * ((double)N[i] - 2)) / (double)N[i]) / (double)360;
    ll total = R[i] * R[i] * N[i];
    // cout << (double)1 / (double)3 * 4 << " " << total << endl;
    cout << (double)juring_part * (double)total << endl;
    p[i] = {abs((((double)1 - juring_part) * (double)total) - (double)juring_part * (double)total), i};
  }
  if (T == 1)
  {
    cout << S[0] << endl;
    return 0;
  }
  sort(p, p + T);
  if (p[T - 1].first == p[T - 2].first)
  {
    cout << "SERI" << endl;
  }
  else
  {
    // cout << p[T - 1].first << endl;
    cout << S[p[T - 1].second] << endl;
  }
>>>>>>> c1b6a3f0b1b1ef713f51ec2409a870fabd40c38b
}
