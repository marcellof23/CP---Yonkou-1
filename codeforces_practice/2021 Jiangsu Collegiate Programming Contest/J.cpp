#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

bool vis[505][505], vis2[505][505];
int grid[505][505];
int col[505][505];

int n, m;

int dirX[4] = {-1, 0, 1, 0};
int dirY[4] = {0, 1, 0, -1};

map<int, pair<int, int>> maps;
vector<pair<int, int>> ans;

void dfs(int i, int j, int color)
{
  vis[i][j] = true;
  col[i][j] = color % 2;

  if (col[i][j] == 0)
    maps[grid[i][j]].first++;
  else
    maps[grid[i][j]].second++;

  for (int k = 0; k < 4; k++)
  {
    int moveX = i + dirX[k];
    int moveY = j + dirY[k];
    if (moveX >= 0 && moveX < n && moveY >= 0 && moveY < m && grid[i][j] == grid[moveX][moveY])
    {
      if (!vis[moveX][moveY])
      {

        dfs(moveX, moveY, color + 1);
      }
    }
  }
}

void dfs2(int i, int j, int color)
{
  vis2[i][j] = true;
  int colr;
  if (maps[grid[i][j]].first < maps[grid[i][j]].second)
  {
    colr = 0;
  }
  else
  {
    colr = 1;
  }
  if (col[i][j] == colr)
  {
    ans.push_back({i + 1, j + 1});
  }
  for (int k = 0; k < 4; k++)
  {
    int moveX = i + dirX[k];
    int moveY = j + dirY[k];
    if (moveX >= 0 && moveX < n && moveY >= 0 && moveY < m && grid[i][j] == grid[moveX][moveY])
    {
      if (!vis2[moveX][moveY])
      {
        dfs2(moveX, moveY, color + 1);
      }
    }
  }
}

void floodfill()
{
  int color = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (!vis[i][j])
      {
        if (!maps.count(grid[i][j]))
        {
          maps[grid[i][j]] = {0, 0};
        }
        dfs(i, j, color);
        dfs2(i, j, color);
        maps[grid[i][j]].first = 0;
        maps[grid[i][j]].second = 0;
      }
    }
  }
}

signed main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(grid, 0, sizeof(grid));
  memset(vis, 0, sizeof(vis));
  memset(col, 0, sizeof(col));

  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> grid[i][j];
    }
  }

  floodfill();

  bool ada = false;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (col[i][j] == 1)
      {
        ada = true;
      }
    }
    if (ada)
      break;
  }

  if (ada)
  {
    cout << 1 << " ";
  }
  else
  {
    cout << 0 << " ";
  }

  // for (int i = 0; i < n; i++)
  // {
  //   for (int j = 0; j < m; j++)
  //   {
  //     int colr;
  //     if (maps[grid[i][j]].first < maps[grid[i][j]].second)
  //     {
  //       colr = 0;
  //     }
  //     else
  //     {
  //       colr = 1;
  //     }

  //     if (col[i][j] == colr)
  //     {
  //       ans.push_back({i + 1, j + 1});
  //     }
  //   }
  // }

  cout << ans.size() << endl;

  for (auto a : ans)
  {
    cout << a.first << " " << a.second << " " << 1 << endl;
  }

  // for (int i = 0; i < n; i++)
  // {
  //   for (int j = 0; j < m; j++)
  //   {
  //     cout << col[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  // cout << endl;

  // for (auto m : maps)
  // {
  //   cout << m.second.first << " " << m.second.second << endl;
  // }
}