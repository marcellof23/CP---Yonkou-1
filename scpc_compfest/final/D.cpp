#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int ssize = s.size();
  int X = 10;
  int Xcount = 0;

  if (ssize == 1)
  {
    if (s[0] == '0' || s[0] == '_' || s[0] == 'X')
    {
      cout << 1 << endl;
    }
    else
    {
      cout << 0 << endl;
    }
    return 0;
  }
  int multiplier = 1;
  if (s[ssize - 1] - '0' == 0)
  {
    if (s[ssize - 2] - '0' >= 1)
    {
      cout << 0 << endl;
      return 0;
    }
    else if (s[ssize - 2] == '_')
    {
      multiplier = 1;
    }
    else if (s[ssize - 2] == 'X')
    {
      if (s[0] == 'X')
      {
        cout << 0 << endl;
        return 0;
      }
      else
      {
        multiplier = 1;
      }
    }
    else
    {
      multiplier = 1;
      if (ssize == 2)
      {
        cout << 1 << endl;
        return 0;
      }
      for (int i = 0; i < ssize - 2; i++)
      {
        if (i == 0 && (s[i] == 'X' || s[i] == '_'))
        {
          multiplier *= 9;
          if (s[i] == 'X')
          {
            X = 9;
            Xcount++;
          }
          continue;
        }
        if (s[i] == 'X')
          Xcount++;
        else if (s[i] == '_')
          multiplier *= 10;
      }
      cout << multiplier << endl;
      return 0;
    }
  }
  else if (s[ssize - 1] - '0' == 5)
  {
    if ((s[ssize - 2] - '0') != 2 && (s[ssize - 2] - '0') != 7 && s[ssize - 2] != '_' && s[ssize - 2] != 'X')
    {
      return 0;
    }
    multiplier = 1;
    if (s[ssize - 2] == '_' || s[ssize - 2] == 'X')
    {
      multiplier = 2;
    }

    for (int i = 0; i < ssize - 2; i++)
    {
      if (i == 0 && (s[i] == 'X' || s[i] == '_'))
      {
        multiplier *= 9;
        if (s[i] == 'X')
        {
          X = 9;
          Xcount++;
        }
        continue;
      }
      if (s[i] == 'X')
        Xcount++;
      else if (s[i] == '_')
      {
        multiplier *= 10;
      }
    }
    cout << multiplier << endl;
    return 0;
  }
  else if (s[ssize - 1] == 'X')
  {
    multiplier = 10;
    if (s[0] == 'X')
    {
      multiplier = 9;
    }
    if (s[ssize - 2] == 'X')
    {
      multiplier *= 2;
    }
    else if (s[ssize - 2] == '_')
    {
      multiplier *= 3;
    }
    for (int i = 0; i < ssize - 2; i++)
    {
      if (i == 0 && (s[i] == 'X' || s[i] == '_'))
      {
        multiplier *= 9;
        if (s[i] == 'X')
        {
          X = 9;
          Xcount++;
        }
        continue;
      }
      if (s[i] == 'X')
        Xcount++;
      else if (s[i] == '_')
      {
        multiplier *= 10;
      }
    }
    cout << multiplier << endl;
  }
  else if (s[ssize - 1] == '_')
  {
    multiplier = 10;
    if (s[ssize - 2] == 'X')
    {
      multiplier *= 2;
    }
    else if (s[ssize - 2] == '_')
    {
      multiplier *= 3;
    }
    for (int i = 0; i < ssize - 2; i++)
    {
      if (i == 0 && (s[i] == 'X' || s[i] == '_'))
      {
        multiplier *= 9;
        if (s[i] == 'X')
        {
          X = 9;
          Xcount++;
        }
        continue;
      }
      if (s[i] == 'X')
        Xcount++;
      else if (s[i] == '_')
      {
        multiplier *= 10;
      }
    }
    cout << multiplier << endl;
  }
  else
  {
    cout << 0 << endl;
    return 0;
  }
  return 0;
}