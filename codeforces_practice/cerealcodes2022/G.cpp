#include <bits/stdc++.h>
using namespace std;

int n, pw, bb;
vector<int> pola[10];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	pola[0].push_back(1);
	pw = 1;
	for(int i=1; i<10; i++){
        if(i%2){
            for(int j=0; j<pw; j++){
                pola[i].push_back(pola[i-1][j]);
            }
            for(int j=0; j<pw; j++){
                pola[i].push_back(pola[i-1][j] + pw);
            }
        }else{
            for(int j=0; j<pw; j++){
                pola[i].push_back(pola[i-1][j] + pw);
            }
            for(int j=0; j<pw; j++){
                pola[i].push_back(pola[i-1][j]);
            }
        }
        /*
        if(i<4){
            for(int j=0; j<pw*2; j++){
                cout << pola[i][j] << " ";
            }cout << endl;
        }
        */
        pw *= 2;
	}

	pw = 1; bb = 0;
	cin >> n;
	for(int i=0; i<n; i++){
        //cout << n%(2*pw) << endl;
        if(n%(2*pw)){
            //cout << "i: " << i << endl;
            if(i%2){
                for(int j=0; j<pw; j++){
                    cout << pola[i][j] + bb + n - pw << " ";
                }
            }else{
                for(int j=0; j<pw; j++){
                    cout << pola[i][j] + bb << " ";
                }
                bb += pw;
            }
        }
        //cout << endl;
        n = n-n%(2*pw);
        pw *= 2;
	}
	cout << endl;
}
