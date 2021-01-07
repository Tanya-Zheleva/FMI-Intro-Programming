#include <iostream>

using namespace std;

bool isValidCell(int** lab, int i, int j, int n, int m, bool** used)
{
    return i >= 0 && i < n && j >= 0 && j < m && lab[i][j] == 1 && !used[i][j];
}

void findIslands(int** lab, int i, int j, int n, int m, bool** used)
{
    if (!isValidCell(lab, i, j, n, m, used))
    {
        return;
    }

    used[i][j] = true;

    findIslands(lab, i - 1, j, n, m, used);
    findIslands(lab, i + 1, j, n, m, used);
    findIslands(lab, i, j - 1, n, m, used);
    findIslands(lab, i, j + 1, n, m, used);
}

void solve(int** lab, int n, int m)
{
    int ans = 0;
    bool** used = new bool* [n];

    for (int i = 0; i < n; i++)
    {
        used[i] = new bool[m];

        for (int j = 0; j < m; j++)
        {
            used[i][j] = false;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (lab[i][j] == 1 && !used[i][j])
            {
                findIslands(lab, i, j, n, m, used);
                ans++;
            }
        }
    }

    cout << ans << endl;

    for (int i = 0; i < n; i++)
    {
        delete[] used[i];
    }

    delete[] used;
}

int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    int** lab = new int* [n];

    for (int i = 0; i < n; i++)
    {
        lab[i] = new int[m];

        for (int j = 0; j < m; j++)
        {
            cin >> lab[i][j];
        }
    }

    solve(lab, n, m);

    for (int i = 0; i < n; i++)
    {
        delete[] lab[i];
    }

    delete[] lab;

    return 0;
}