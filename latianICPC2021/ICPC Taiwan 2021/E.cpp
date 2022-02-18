//#include <boost/multiprecision/cpp_int.hpp>
#include <bits/stdc++.h>
using namespace std;

long long inf = 1000000000000000001;
long long p5(long long x){
    return x*x*x*x*x;
}
/*
boost::multiprecision::cpp_int big1 = 1, big2 = 2, big12 = 12;
boost::multiprecision::cpp_int formula(boost::multiprecision::cpp_int x){
    return x*x*(x+big1)*(x+big1)*(big2*x*x + big2*x*x - big1)/big12;
}
*/

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long p, q, x, y, d;
    cin >> p >> q;
    long long lo = 1, hi = inf, m;
    long long cur = -1;
    d = 0; x = p;
    while(cur<0){
        d++;
        cur = q * p5(d) - p;
        x -= cur*(cur<0);
    }
    cout << x << endl;
    /*
    double ln = log(10) * 111.0 + log(6) - log(q);
    y = ceil(exp(ln/6.0));
    cout << y/100 << endl;
    */
    x = pow((double) 6000.0 / q, (double) 1.0/6.0);
    y = pow((double) 6000.0 / q, (double) 1.0/6.0) * 1e16;
    cout << x+y << endl;
    /*
    boost::multiprecision::cpp_int bigP, bigQ, bigL, bigR, bigX, bigY, goal;
    bigL = 0; bigR = inf;
    bigP = p; bigQ = q; bigX = x;
    goal = 1;
    for(int i=0; i<99; i++){
        goal *= 10;
    }
    while(bigR - bigL > bigOne){
        bigY = (bigR + bigL) / (bigOne + bigOne);
        if(bigX + bigQ*formula(bigY) - bigP*bigY >= goal){
            bigR = bigY;
        }else{
            bigL = bigY;
        }
    }
    cout << bigR << endl;
    */
}
