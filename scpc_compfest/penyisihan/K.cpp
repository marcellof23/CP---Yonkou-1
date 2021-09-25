#include <bits/stdc++.h>
using namespace std;

string board[100069];

deque<deque<char>> subgrid[100069];
deque<deque<char>> revsubgrid[100069];
deque<deque<char>> invsubgrid[100069];
deque<deque<char>> revinvsubgrid[100069];

deque<char> substring[100069];
deque<char> invsubstring[100069];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    unordered_set<deque<deque<char>>> us;

    long long n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> board[i];
    }
    long long l = 0, r = min(n, m), k;
    while (r - l > 0)
    {
        us.clear();
        long long k = (r + l) / 2;
        bool found = false;
        //isi semua substring
        for (int i = 0; i < n; i++)
        {
            substring[i].clear();
            for (int j = 0; j < k; j++)
            {
                substring[i].push_back(board[i][j]);
            }
        }
        //isi semua invsubstring
        for (int i = 0; i < m; i++)
        {
            invsubstring[i].clear();
            for (int j = 0; j < k; j++)
            {
                substring[i].push_back(board[j][i]);
            }
        }

        //isi semua subgrid
        for (int i = 0; i < k; i++)
        {
            subgrid[0].push_back(substring[i]);
            for (int j = 1; j <= m - k; j++)
            {
                substring[i].pop_front();
                substring[i].push_back(board[i][j + k - 1]);
                subgrid[j].push_back(substring[i]);
                revsubgrid[j].push_front(substring[i]);
            }
            invsubgrid[0].push_back(invsubstring[i]);
            for (int j = 1; j <= n - k; j++)
            {
                invsubstring[i].pop_front();
                invsubstring[i].push_back(board[j + k - 1][i]);
                invsubgrid[j].push_back(invsubstring[i]);
                revinvsubgrid[j].push_front(invsubstring[i]);
            }
        }

        //balikin semua substring
        for (int i = 0; i < n; i++)
        {
            substring[i].clear();
            for (int j = 0; j < k; j++)
            {
                substring[i].push_back(board[i][j]);
            }
        }
        //balikin semua invsubstring
        for (int i = 0; i < m; i++)
        {
            invsubstring[i].clear();
            for (int j = 0; j < k; j++)
            {
                substring[i].push_back(board[j][i]);
            }
        }

        //masukin ke hash
        for (int i = 0; i <= n - k; i++)
        {
            found = (found || us.find(subgrid[0]) != us.end());
            us.insert(subgrid[0]);
            if (subgrid[0] != revsubgrid[0])
            {
                found = (found || us.find(revsubgrid[0]) != us.end());
                us.insert(revsubgrid[0]);
            }
            if (subgrid[0] != invsubgrid[i] && revsubgrid[0] != invsubgrid[i])
            {
                found = (found || us.find(invsubgrid[i]) != us.end());
                us.insert(invsubgrid[i]);
            }
            if (subgrid[0] != revinvsubgrid[i] && revsubgrid[0] != revinvsubgrid[i] && invsubgrid[i] != revinvsubgrid[i])
            {
                found = (found || us.find(revinvsubgrid[i]) != us.end());
                us.insert(revinvsubgrid[i]);
            }
            //proses subgrid
            if (i < n - k)
            {
                subgrid[0].pop_front();
                subgrid[0].push_back(substring[i + k]);
                if (k < m)
                {
                    substring[i + k].pop_front();
                    substring[i + k].push_back(board[i + k][k]);
                }
            }

            for (int j = 1; j <= m - k; j++)
            {
                //proses invsubgrid
                invsubgrid[i].pop_front();
                revinvsubgrid[i].pop_back();
                invsubgrid[i].push_back(invsubstring[j + k - 1]);
                invsubgrid[i].push_front(invsubstring[j + k - 1]);
                if (j < m - k)
                {
                    invsubstring[j + k - 1].pop_front();
                    invsubstring[j + k - 1].push_back(board[i + k - 1][j + k]);
                }

                found = (found || us.find(subgrid[j]) != us.end());
                us.insert(subgrid[j]);
                if (subgrid[j] != revsubgrid[j])
                {
                    found = (found || us.find(revsubgrid[j]) != us.end());
                    us.insert(revsubgrid[j]);
                }
                if (subgrid[j] != invsubgrid[i] && revsubgrid[j] != invsubgrid[i])
                {
                    found = (found || us.find(invsubgrid[i]) != us.end());
                    us.insert(invsubgrid[i]);
                }
                if (subgrid[j] != revinvsubgrid[i] && revsubgrid[j] != revinvsubgrid[i] && invsubgrid[i] != revinvsubgrid[i])
                {
                    found = (found || us.find(revinvsubgrid[i]) != us.end());
                    us.insert(revinvsubgrid[i]);
                }

                //proses subgrid
                if (i < n - k)
                {
                    subgrid[j].pop_front();
                    subgrid[j].push_back(substring[i + k]);
                    if (j < m - k)
                    {
                        substring[i + k].pop_front();
                        substring[i + k].push_back(board[i + k][j + k]);
                    }
                }
            }
        }

        if (found)
        {
            l = k;
        }
        else
        {
            r = k;
        }
    }
    cout << r << endl;
    return 0;
}
