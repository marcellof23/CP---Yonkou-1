#include <bits/stdc++.h>
using namespace std;

struct ans
{
  int l1;
  int r1;
  int l2;
  int r2;
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int R, C, Q;
  cin >> R >> C >> Q;
  char grid[R][C];

  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++)
    {
      cin >> grid[i][j];
    }
  }

  struct vector<ans> answ;

  while (Q--)
  {
    string s;
    cin >> s;
    int ssize = s.size();
    bool valid = false;
    for (int i = 0; i < R; i++)
    {
      if (valid)
      {
        break;
      }
      for (int j = 0; j < C; j++)
      {
        int dir[8];
        for (int k = 0; k < ssize; k++)
        {
          if (i + k < R)
          {
            if (s[k] == grid[i + k][j])
              dir[0]++;
          }
          if (i + k < R && j - k >= 0)
          {
            if (s[k] == grid[i + k][j - k])
              dir[1]++;
          }
          if (j - k >= 0)
          {
            if (s[k] == grid[i][j - k])
              dir[2]++;
          }
          if (i - k >= 0 && j - k >= 0)
          {
            if (s[k] == grid[i - k][j - k])
              dir[3]++;
          }
          if (i - k >= 0)
          {
            if (s[k] == grid[i - k][j])
              dir[4]++;
          }
          if (i - k >= 0 && j + k < C)
          {
            if (s[k] == grid[i - k][j + k])
              dir[5]++;
          }
          if (j + k < C)
          {
            if (s[k] == grid[i][j + k])
              dir[6]++;
          }
          if (i + k < R && j + k < C)
          {
            if (s[k] == grid[i + k][j + k])
              dir[7]++;
          }
        }
        if (dir[0] == ssize)
        {
          ans an;
          an.l1 = i;
          an.r1 = j;
          an.l2 = i + ssize - 1;
          an.r2 = j;
          answ.push_back(an);
          valid = true;
        }
        else if (dir[1] == ssize)
        {
          ans an;
          an.l1 = i;
          an.r1 = j;
          an.l2 = i + ssize - 1;
          an.r2 = j - ssize + 1;
          answ.push_back(an);
          valid = true;
        }
        else if (dir[2] == ssize)
        {
          ans an;
          an.l1 = i;
          an.r1 = j;
          an.l2 = i;
          an.r2 = j - ssize + 1;
          answ.push_back(an);
          valid = true;
        }
        else if (dir[3] == ssize)
        {
          ans an;
          an.l1 = i;
          an.r1 = j;
          an.l2 = i - ssize + 1;
          an.r2 = j - ssize + 1;
          answ.push_back(an);
          valid = true;
        }
        else if (dir[4] == ssize)
        {
          ans an;
          an.l1 = i;
          an.r1 = j;
          an.l2 = i - ssize + 1;
          an.r2 = j;
          answ.push_back(an);
          valid = true;
        }
        else if (dir[5] == ssize)
        {
          ans an;
          an.l1 = i;
          an.r1 = j;
          an.l2 = i - ssize + 1;
          an.r2 = j + ssize - 1;
          answ.push_back(an);
          valid = true;
        }
        else if (dir[6] == ssize)
        {
          ans an;
          an.l1 = i;
          an.r1 = j;
          an.l2 = i;
          an.r2 = j + ssize - 1;
          answ.push_back(an);
          valid = true;
        }
        else if (dir[7] == ssize)
        {
          ans an;
          an.l1 = i;
          an.r1 = j;
          an.l2 = i + ssize - 1;
          an.r2 = j + ssize - 1;
          answ.push_back(an);
          valid = true;
        }
      }
    }
    if (!valid)
    {
      ans an;
      an.l1 = -1;
      answ.push_back(an);
    }
  }
  for (auto a : answ)
  {
    if (a.l1 == -1)
    {
      cout << -1 << endl;
    }
    else
    {
      cout << a.l1 << " " << a.r1 << " " << a.l2 << " " << a.r2 << endl;
    }
  }
}
