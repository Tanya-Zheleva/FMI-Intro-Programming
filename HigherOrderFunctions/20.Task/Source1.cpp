#include <iostream>
#include <algorithm>
#include "BullsAndCows.h"
using namespace std;

const int* tryGuess(int x);

void my_diff(int x, int y, int* res)
{
    int dx[4], dy[4];
    for (int i = 0; i < 4; i++)
    {
        dx[i] = x % 10;
        dy[i] = y % 10;

        x /= 10;
        y /= 10;
    }

    res[0] = res[1] = 0;
    for (int i = 0; i < 4; i++)
    {
        if (dx[i] == dy[i])
            res[0]++;
        for (int j = 0; j < 4; j++)
        {
            if (dx[i] == dy[j])
                res[1]++;
        }
    }

    res[1] -= res[0];
}

int count_valid(int x, int* g, int n, int* valid, int* t)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        my_diff(x, valid[i], t);
        if (t[0] == g[0] && t[1] == g[1])
            res++;
    }
    return res;
}

double eval(int x, int(*combos)[2], int n, int* valid, double best_eval)
{
    double res = 0;
    int* t = new int[2];
    for (int i = 12; i > 0; i--)
    {
        res = max(res, (double)count_valid(x, combos[i], n, valid, t));
        if (res > best_eval)
            return best_eval + 1;
    }
    delete[] t;

    return res;
}

void rethink_valid(int x, const int* g, int& n, int*& valid)
{
    int passed = 0;
    int* t = new int[2];
    for (int i = 0; i < n; i++)
    {
        my_diff(x, valid[i], t);
        if (t[0] == g[0] && t[1] == g[1])
            passed++;
    }

    int* now_valid = new int[passed];
    passed = 0;
    for (int i = 0; i < n; i++)
    {
        my_diff(x, valid[i], t);
        if (t[0] == g[0] && t[1] == g[1])
            now_valid[passed++] = valid[i];
    }

    delete[] valid;
    delete[] t;
    valid = now_valid;
    n = passed;
}

void play()
{

    int passed = 0;
    for (int i = 1000; i <= 9999; i++)
    {
        int dig[10], temp = i;
        for (int j = 0; j < 10; j++)
            dig[j] = 0;

        bool good = true;
        while (temp)
        {
            dig[temp % 10]++;
            if (dig[temp % 10] == 2)
                good = false;
            if (temp % 10 == 0)
                good = false;
            temp /= 10;
        }

        if (good)
            passed++;
    }

    int* valid = new int[passed];
    int n = 0;
    for (int i = 1000; i <= 9999; i++)
    {
        int dig[10], temp = i;
        for (int j = 0; j < 10; j++)
            dig[j] = 0;

        bool good = true;
        while (temp)
        {
            dig[temp % 10]++;
            if (dig[temp % 10] == 2)
                good = false;
            if (temp % 10 == 0)
                good = false;
            temp /= 10;
        }

        if (good)
            valid[n++] = i;
    }

    int combos[13][2] = { {3, 0},
                         {2, 2},
                         {2, 1},
                         {2, 0},
                         {1, 3},
                         {1, 2},
                         {1, 1},
                         {1, 0},
                         {0, 0},
                         {0, 1},
                         {0, 2},
                         {0, 3},
                         {0, 4} };


    int turns = 0;
    while (1) /// dokato ne poznaem
    {
        double best_eval = 10000;
        int rem_x = 0;
        rem_x = valid[(rand() * rand()) % n];
        if (turns)
        {
            for (int i = 0; i < n; i++)
            {
                double cur = eval(valid[i], combos, n, valid, best_eval);
                if (cur < best_eval)
                {
                    best_eval = cur;
                    rem_x = valid[i];
                }
            }
        }
        else
            rem_x = 4567;


        const int* g = tryGuess(rem_x);
        turns++;
        if (g[0] == 4)
        {
            cout << rem_x << " guessed in " << turns << " turns" << endl;
            ///poznahme
            break;
        }
        rethink_valid(rem_x, g, n, valid);
    }
}


