#include <bits/stdc++.h>
using namespace std;

long long n, a[200069];
long long l, r, last = -1;
long long inc[200069], decr[200069];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i=0; i<n; i++){
        cin >> a[i];
	}
	inc[n-1] = 1;
	for(int i=n-2; i>=0; i--){
        if(a[i] < a[i+1]){
            inc[i] = inc[i+1]+1;
        }else{
            inc[i] = 1;
        }
	}
	decr[0] = 1;
	for(int i=1; i<n; i++){
        if(a[i] < a[i-1]){
            decr[i] = decr[i-1]+1;
        }else{
            decr[i] = 1;
        }
	}

	int itr = 0;
	l = 0; r = n-1;
	while(l<=r && last<max(a[l], a[r])){
        if(a[l] <= last){
            last = a[r];
            r--;
        }else if(a[r] <= last){
            last = a[l];
            l++;
        }else{
            if(a[l]<a[r]){
                if(decr[r]%2){
                    last = a[r];
                    r--;
                }else{
                    last = a[l];
                    l++;
                }
            }else{
                if(inc[l]%2){
                    last = a[l];
                    l++;
                }else{
                    last = a[r];
                    r--;
                }
            }
        }
        itr++;
	}
	if(itr%2){
        cout << "Alice" << endl;
	}else{
        cout << "Bob" << endl;
	}
}
