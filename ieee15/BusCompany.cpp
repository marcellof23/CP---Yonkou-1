#include <bits/stdc++.h>
using namespace std;

const long long maxn = 262144;
long long n, q;
bool isB[maxn];
vector<long long> al[maxn];
//preorder purposes
long long depth[maxn], range[maxn][2], curRange = 0;
//binary lifting
long long parent[20][maxn];

void init(){
    for(int i=1; i<=n; i++){
        cin >> isB[i];
        range[i][0] = -1; //vis=false
    }
    long long u, v;
    for(int i=1; i<n; i++){
        cin >> u >> v;
        al[u].push_back(v);
        al[v].push_back(u);
    }
}
void dfs(long long node, long long d){
    range[node][0] = curRange;
    depth[node] = d;
    curRange++;
    for(int i=0; i<al[node].size(); i++){
        long long expand = al[node][i];
        if(range[expand][0]<0){//belom di visit
            parent[0][expand] = node;
            dfs(expand, d+1);
        }
    }
    range[node][1] = curRange-1;
}
void binary_lifting(){
    for(int i=1; i<20; i++){
        for(int j=0; j<=maxn; j++){
            parent[i][j] = parent[i-1][parent[i-1][j]];
        }
    }
}
long long getParent(long long node, long long x){
    for(int i=0; x>0; i++){
        if(x%2){
            node = parent[i][node];
        }
        x/=2;
    }
    return node;
}
bool isAncestor(long long x, long long y){
    return (range[x][0] <= range[y][0]) && (range[x][1] >= range[y][1]);
}

void print_range(){
    for(int i=1; i<=n; i++){
        cout << i << " " << range[i][0] << " " << range[i][1] << endl;
    }
}
void print_bl(long long d){
    for(int i=0; i<d; i++){
        for(int j=0; j<=n; j++){
            cout << parent[i][j] << " ";
        }cout << endl;
    }
}

//segtree purposes: [A, B][nb(X), path(X), sum(nb(X) to root)]
long long segtree[6][2*maxn];
void update(long long id, long long node, long long addval){
    node += maxn;
    while(node>0){
        segtree[id][node] += addval; node/=2;
    }
}
long long query(long long id, long long lo, long long hi){
    lo += maxn; hi += maxn;
    long long res = 0;
    while(lo<=hi){
        if(lo%2){res += segtree[id][lo];}
        lo = (lo+1)/2;
        if(hi%2==0){res += segtree[id][hi];}
        hi = (hi-1)/2;
    }
    return res;
}

long long nb(long long node, bool isA){
    return query(3*(!isA), range[node][0], range[node][1]);
}
long long path(long long node, bool isA){
    return query(3*(!isA) +1, range[node][0], range[node][1]) - depth[node]*nb(node, isA);
}
long long nbs(long long node, bool isA){
    return query(3*(!isA) +2, 0, range[node][0]);
}
void updateNode(long long node, long long val){
    update(3*isB[node], range[node][0], val);
    update(3*isB[node]+1, range[node][0], val*depth[node]);
}
void updateNode2(long long node, long long val){
    cout << "update2 ";
    long long save = nb(node, 1);
    cout << save << " ";
    update(2, range[node][0], val*save);
    update(2, range[node][1]+1, -val*save);
    save = nb(node, 0);
    cout << save << endl;
    update(5, range[node][0], val*save);
    update(5, range[node][1]+1, -val*save);
}
void print_prefix(){
    for(int i=0; i<=n; i++){
        cout << segtree[2][maxn+i] << " ";
    }cout << endl;
    for(int i=0; i<=n; i++){
        cout << segtree[5][maxn+i] << " ";
    }cout << endl;
}
void build(){
    //gatau perlu atau engga
    for(int id=0; id<6; id++){
        for(int i=0; i<2*maxn; i++){
            segtree[id][i] = 0;
        }
    }
    for(int node=1; node<=n; node++){
        updateNode(node, 1);
    }
    for(int node=1; node<=n; node++){
        updateNode2(node, 1);
    }
}
long long print_segtree(){
    for(int i=1; i<=n; i++){
        cout << i << " " << nb(i, 1) << " " << path(i, 1) << " " << nbs(i, 1) << " " << nb(i, 0) << " " << path(i, 0) << " " << nbs(i, 0) << endl;
    }
}

int main() {
    cin >> n;
    init();
    dfs(1, 0);
    //cout << "range" << endl;
    print_range();
    binary_lifting();
    //cout << "bl" << endl;
    //print_bl(4);
    build();
    //print_segtree();
    cin >> q;
    long long a, b, c, d; //d itu anak parent yg ngarah ke child
    while(q--){
        cin >> a;
        if(a==1){
            cin >> b;
            print_prefix();
            print_segtree();
            updateNode2(b,-1);
            updateNode(b,-1);
            cout << endl;
            print_prefix();
            print_segtree();
            cout << endl;
            isB[b] = !isB[b];
            updateNode(b, 1);
            updateNode2(b, 1);
            print_prefix();
            print_segtree();
        }else{
            cin >> b >> c;
            if(depth[b]>depth[c]){
                d = b;
                b = c;
                c = d;
            }
            cout << b << " " << c << endl;
            double A[2][2], B[2][2];
            if(isAncestor(b, c)){

                d = getParent(c, depth[c]-depth[b]-1);
                cout << d << endl << endl;
                cout << path(1, 1) << endl;
                cout << path(d, 1) << endl;
                cout << depth[b]+2 << endl;
                cout << nb(1, 1) << endl;
                cout << nbs(b, 1) << endl;
                cout << nb(d, 1) << endl;
                A[0][0] = path(1, 1) - path(d, 1) + (depth[b]+2)*nb(1, 1) - 2*nbs(b, 1) - nb(d, 1);
                A[0][1] = path(c, 1);
                A[1][0] = nb(1, 1) - nb(d, 1);
                A[1][1] = nb(c, 1);

                B[0][0] = path(1, 0) - path(d, 0) + (depth[b]+2)*nb(1, 0) - 2*nbs(b, 0) - nb(d, 0);
                B[0][1] = path(c, 0);
                B[1][0] = nb(1, 0) - nb(d, 0);
                B[1][1] = nb(c, 0);
            }else{
                A[0][0] = path(b, 1);
                A[0][1] = path(c, 1);
                A[1][0] = nb(b, 1);
                A[1][1] = nb(c, 1);
                B[0][0] = path(b, 0);
                B[0][1] = path(c, 0);
                B[1][0] = nb(b, 0);
                B[1][1] = nb(c, 0);
            }
            if(A[1][0]*A[1][1] == 0){
                if(B[1][0]*B[1][1] == 0){
                    cout << "TIE" << endl;
                }else{
                    cout << "B" << endl;
                }
            }else if(B[1][0]*B[1][1] == 0){
                cout << "A" << endl;
            }else{
                double ansA = A[0][0]/A[1][0] + A[0][1]/A[1][1];
                double ansB = B[0][0]/B[1][0] + B[0][1]/B[1][1];
                cout << A[0][0] << "/" << A[1][0] << " " << A[0][1] << "/" << A[1][1] << endl;
                cout << B[0][0] << "/" << B[1][0] << " " << B[0][1] << "/" << B[1][1] << endl;
                cout << ansA << " " << ansB << endl;
                if(ansA>ansB){
                    cout << "B" << endl;
                }else if(ansA<ansB){
                    cout << "A" << endl;
                }else{
                    cout << "TIE" << endl;
                }
            }
        }
    }
}
