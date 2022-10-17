#include <bits/stdc++.h>
using namespace std;
#define pll pair<long long,long long>

const long long xmax = 1e9;

void out(pll p){
    cout << "(" << p.first << "," << p.second << ")";
}
bool isSame(pll a, pll b){
    return (a.first == b.first) && (a.second == b.second);
}

bool isColinear(pll p0, pll p1, pll p2){
    // (p2.y - p0.y)/(p2.x - p0.x) = (p1.y - p0.y)/(p1.x - p0.x)
    return (p2.second - p0.second) * (p1.first - p0.first)
        == (p2.first - p0.first) * (p1.second - p0.second);
}

bool isInLine(pll p0, pll p1, pll p2){
    return min(p0.first, p1.first) <= p2.first
        && p2.first <= max(p0.first, p1.first)
        && min(p0.second, p1.second) <= p2.second
        && p2.second <= max(p0.second, p1.second);
}

bool isParalel(pll p0, pll p1, pll p2, pll p3){
    // (p1.y-p0.y)/(p1.x-p0.x) == (p3.y-p2.y)/(p3.x-p2.x)
    return (p1.second-p0.second) * (p3.first-p2.first)
        == (p1.first-p0.first) * (p3.second-p2.second);
}

bool isBetween01(long long num, long long den){
    //cout << num << " " << den << endl;
    return (num == 0)
        || ((abs(num)/num == abs(den)/den)
        && abs(num) <= abs(den));
}

bool isIntersect (pll p0, pll p1, pll p2, pll p3){
    if(isParalel(p0, p1, p2, p3)){
        return (isColinear(p0, p1, p2) && isInLine(p0, p1, p2))
            || (isColinear(p0, p1, p3) && isInLine(p0, p1, p3))
            || (isColinear(p2, p3, p0) && isInLine(p2, p3, p0))
            || (isColinear(p2, p3, p1) && isInLine(p2, p3, p1));
    }else{
        long long tnum = (p0.first-p2.first)*(p2.second-p3.second) - (p0.second-p2.second)*(p2.first-p3.first);
        long long unum = (p0.first-p2.first)*(p0.second-p1.second) - (p0.second-p2.second)*(p0.first-p1.first);
        long long den = (p0.first-p1.first)*(p2.second-p3.second) - (p0.second-p1.second)*(p2.first-p3.first);
        //cout << tnum << " " << unum << " " << den << endl;
        return isBetween01(tnum, den) && isBetween01(unum, den);
    }
}

int isInside(vector<pll>& polygon, pll point){
    // Return -1 outside, 0 on line, 1 inside
    int sz = polygon.size();
    for(int i=0; i<sz; i++){
        if(isColinear(polygon[i], polygon[(i+1)%sz], point)
           && isInLine(polygon[i], polygon[(i+1)%sz], point)){
            return 0;
        }
    }
    // Dijamin point, farRight gada titik didalem garis ini
    pll farRight;
    farRight.first = point.first + 2*xmax + 1;
    farRight.second = point.second + 1;
    int toReturn = -1;
    for(int i=0; i<sz; i++){
        if(isIntersect(point, farRight, polygon[i], polygon[(i+1)%sz])){
            toReturn *= -1;
        }
    }
    return toReturn;
}

bool isGradientGreater(pll p0, pll p1, pll p2, pll p3){
    pll temp;
    if(p1 < p0){
        temp = p1; p1 = p0; p0 = temp;
    }
    if(p3 < p2){
        temp = p2; p2 = p3; p3 = temp;
    }
    //(p1.y-p0.y)/(p1.x-p0.x) >= (p3.y-p2.y)/(p3.x-p2.x);
    return (p1.second - p0.second) * (p3.first - p2.first) > (p1.first - p0.first) * (p3.second - p2.second);
}

vector<pll> convexHull(vector<pll> polygon){
    int sz = polygon.size();
    sort(polygon.begin(), polygon.end());
    vector<pll> chu, chd;
    chu.push_back(polygon[0]); chu.push_back(polygon[1]);
    chd.push_back(polygon[0]); chd.push_back(polygon[1]);
    int szu = 2, szd = 2;
    for(int i=2; i<sz; i++){
        //cout << polygon[i].first << " " << polygon[i].second << endl;
        while(szu >= 2 && isGradientGreater(chu[szu-2], polygon[i], chu[szu-2], chu[szu-1])){
            chu.pop_back(); szu--;
        }
        chu.push_back(polygon[i]); szu++;
        while(szd >= 2 && isGradientGreater(chd[szd-2], chd[szd-1], chd[szd-2], polygon[i])){
            chd.pop_back(); szd--;
        }
        chd.push_back(polygon[i]); szd++;
        //cout << i << " " << szu << " " << szd << endl;
    }
    for(int i=szd-2; i>0; i--){
        chu.push_back(chd[i]);
    }
    return chu;
}

double dis(pll a, pll b){
    return sqrt((double) (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}

vector<pll> inside, outside, chi, cho, chm;
pll point;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //Input
    long long n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> point.first >> point.second;
        inside.push_back(point);
    }
    for(int i=0; i<m; i++){
        cin >> point.first >> point.second;
        outside.push_back(point);
    }
    chi = convexHull(inside);
    /*
    for(int i=0; i<chi.size(); i++){
        out(chi[i]);
    }cout << endl;
    */
    //Cari tahu arah
    int clockwise = 1, firstIdx = 0;
    while(inside[firstIdx] != chi[1]){
        firstIdx++;
    }
    do{
        /*
        out(inside[firstIdx]);
        out(chi[0]);
        cout << endl;
        */
        firstIdx = (firstIdx+1)%n;
        if(inside[firstIdx] == chi[0]){
            clockwise = -1;
        }
    }while(inside[firstIdx] != chi[0] && inside[firstIdx] != chi[2]);

    double ans = 0.0;
    firstIdx = 0;
    while(inside[firstIdx] != chi[0]){
        firstIdx++;
    }
    for(int i=0; i<chi.size(); i++){
        chm.clear();
        cho.clear();
        chm.push_back(inside[firstIdx]);
        cho.push_back(inside[firstIdx]);
        while(chi[(i+1)%chi.size()] != inside[firstIdx]){
            firstIdx = (firstIdx+1)%n;
            cho.push_back(inside[firstIdx]);
        }
        chm.push_back(inside[firstIdx]);

        for(int j=0; j<m; j++){
            if(isInside(cho, outside[j]) >= 0){
                chm.push_back(outside[j]);
            }
        }
        chm = convexHull(chm);

        ans += dis(chm[0], chm[chm.size()-1]);
        for(int j=1; j<chm.size(); j++){
            ans += dis(chm[j-1], chm[j]);
        }
    }
    ans -= dis(chi[0], chi[chi.size()-1]);
    for(int i=1; i<chi.size(); i++){
        ans -= dis(chi[i-1], chi[i]);
    }
    cout << fixed << setprecision(9) << ans << endl;
}
