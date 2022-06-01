#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    long long n;
    cin >> n;
    cout << n/2 << endl;
    for(int i=0; i<n; i++){
        cout << 1 + (i + n/2)%n << " ";
    }cout << endl << endl;
}
