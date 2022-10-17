#include <bits/stdc++.h>
using namespace std;

int lps[262144];

int occ(string pat, string txt){
    lps[0] = 0;
    int i=1, j=0;
    while(i<pat.length()){
        if(pat[i] == pat[j]){
            j++;
            lps[i] = j;
            i++;
        }else if(j==0){
            lps[i] = 0;
            i++;
        }else{
            j = lps[j-1];
        }
    }
    i=0; j=0;
    int ret = 0;
    while(i<txt.length()){
        if(txt[i] == pat[j]){
            j++;
            i++;
        }else if(j==0){
            i++;
        }else if(j==pat.length()){
            ret++;
            j=0;
        }else{
            j = lps[j-1];
        }
    }
    if(j==pat.length()){ret++;}
    return ret;
}

long long t;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string pat, txt;
    cin >> t;
    for(int tt=1; tt<=t; tt++){
        cin >> txt >> pat;
        cout << "Case #" << tt << ": " << occ(pat, txt) << endl;
    }
}
