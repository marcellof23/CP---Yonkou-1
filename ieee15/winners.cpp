#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  vector<string> coba = {
      "Team 1",
      "Knapsackers@UNT",
      "MoraSeekers",
      "SurpriseTeam",
      "CuSAT",
      "DongskarPedongi",
      "cofrades",
      "viRUs",
      "TeamName",
      "TeamEPFL1",
      "whatevs",
      "WildCornAncestors",
      "TheCornInTheFields",
      "Aurora"};

  for (string s : coba)
  {
    cout << (s[s.size() - 4]) << "";
    // cout << s;
    // for (int i = 14; i < 25; i++)
    //   cout << ' ' << (s[3] ^ s[4]) * 8 % i << ' ';
    // cout << endl;
  }
  int arr[14] = {9, 3, 16, 2, 4, 3, 2, 4, 1, 6, 0, 5, 10, 12};
  return 0;
}