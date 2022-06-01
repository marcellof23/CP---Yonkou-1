#include <bits/stdc++.h>

using namespace std;
long long m, n;
long long board[1010][1010], dis[1010][1010];
queue<long long> q[2];
vector<long long> tel[300][2];

void enqueue_tel(int id, int todis){
	for(int i=0; i<tel[id][0].size(); i++){
		int x = tel[id][0][i];
		int y = tel[id][1][i];
		q[0].push(x);
		q[1].push(y);
		dis[x][y] = todis;
	}
}

void nq(int x, int y, int todis){
	if(board[x][y]){
		enqueue_tel(board[x][y], todis);
	}else{
		q[0].push(x);
		q[1].push(y);
		dis[x][y] = todis;
	}
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> m >> n;
	//init board dan distance
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cin >> board[i][j];
			tel[board[i][j]][0].push_back(i);
			tel[board[i][j]][1].push_back(j);
			dis[i][j] = 1e9;
		}
	}

	nq(0, 0, 0);

	while(!(q[0].empty())){
		long long headx = q[0].front();
		long long heady = q[1].front();
		q[0].pop(); q[1].pop();
		long long todis = dis[headx][heady] + 1;
		if(headx > 0){
			if(dis[headx-1][heady] == 1e9){
				nq(headx-1, heady, todis);
			}
		}
		if(headx < m-1){
			if(dis[headx+1][heady] == 1e9){
				nq(headx+1, heady, todis);
			}
		}
		if(heady > 0){
			if(dis[headx][heady-1] == 1e9){
				nq(headx, heady-1, todis);
			}
		}
		if(headx < n-1){
			if(dis[headx][heady+1] == 1e9){
				nq(headx, heady+1, todis);
			}
		}
	}
	cout << dis[n-1][m-1] << endl;
}
