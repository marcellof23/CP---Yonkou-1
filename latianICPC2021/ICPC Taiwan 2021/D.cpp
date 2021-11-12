//#include <boost/multiprecision/cpp_int.hpp>
#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    double n;
    cin >> n;
    cout << fixed << setprecision(9) << n/(n+n-2.0) << endl;
}
