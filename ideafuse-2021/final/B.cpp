#include <bits/stdc++.h>
using namespace std;



int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
    long long t, n, k;
    cin >> t;
    for(int tt=1; tt<=t; tt++){
        cin >> n >> k;
        long long idx = 0;
        stack <long long> st;
        while(n>0){
            if(n%2){
                st.push(idx);
                k--;
            }
            idx++;
            n /= 2;
        }
        long long greatest = st.top();
        long long nb = 0;
        while(k>0){
            while(!st.empty() && st.top() == greatest){
                nb++;
                st.pop();
            }
            if(nb<=k){
                k-=nb;
                greatest--;
                nb*=2;
            }else{
                while(k>0){
                    st.push(greatest-1);
                    st.push(greatest-1);
                    k--;
                    nb--;
                }
            }
        }
        while(nb>0){
            st.push(greatest);
            nb--;
        }
        if(k<0){
            cout << "Case #" << tt << ": No" << endl;
        }else{
            cout << "Case #" << tt << ":";
            while(!st.empty()){
                cout << " " << st.top();
                st.pop();
            }cout << endl;
        }

    }
	return 0;
}
