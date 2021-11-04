#include <bits/stdc++.h>
using namespace std;
#define ll long long

long long n;
long long a[1010];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){cout << 'a';}
    for(int i=0; i<n; i++){cout << 'b';}
    cout << endl;
    for(int i=1; i<n; i++){cout << 'a';}
    cout << "ba";
    for(int i=1; i<n; i++){cout << 'b';}
    cout << endl;
}
