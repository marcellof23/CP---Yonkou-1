#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N;
  cin >> N;
  int grid[N][N];
  memset(grid, 0, sizeof(grid));
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> grid[i][j];
    }
  }

  int rows[N];
  int cols[N];
  memset(rows, 0, sizeof(rows));
  memset(cols, 0, sizeof(cols));

  int curr_row = 0, curr_col;
  for (int i = 0; i < N; i++)
  {
    curr_row = 0;
    for (int j = 0; j < N; j++)
    {
      if (curr_row < grid[i][j])
      {
        curr_row = grid[i][j];
        rows[i]++;
      }
    }
  }

  for (int j = 0; j < N; j++)
  {
    curr_col = 0;
    for (int i = 0; i < N; i++)
    {
      if (curr_col < grid[i][j])
      {
        curr_col = grid[i][j];
        cols[j]++;
      }
    }
  }

  for (int i = 0; i < N; i++)
  {
    if (cols[i] == 0)
    {
      cout << 1 << " ";
    }
    else
      cout << cols[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < N; i++)
  {
    if (rows[i] == 0)
    {
      cout << 1 << endl;
    }
    else
      cout << rows[i] << endl;
  }
}