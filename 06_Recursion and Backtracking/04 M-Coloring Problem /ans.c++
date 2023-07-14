// Question Link : https://www.codingninjas.com/studio/problems/m-coloring-problem_981273?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

bool f(int index, int n, int m, vector<vector<int>> &mat, vector<int> &colored)
{
    for (int i = 0; i < m; i += 1)
    {
        // Assigning a color to curr node
        bool helper = true;
        colored[index] = i;
        // Now calling on its neighbours
        for (int j = 0; j < n; j += 1)
        {
            if (mat[index][j] == 1)
            {
                if (colored[j] == -1)
                {
                    helper = helper && f(j, n, m, mat, colored);
                }
                else
                {
                    if (colored[j] == colored[index])
                    {
                        helper = helper && false;
                    }
                    else
                    {
                        helper = helper && true;
                    }
                }
            }
        }
        if (helper == true)
        {
            return true;
        }
    }

    return false;
}

string graphColoring(vector<vector<int>> &mat, int m)
{

    // Let vertices be from 0 to n-1
    int n = mat.size();
    vector<int> colored(n, -1);
    bool ans = true;

    // This is done because our graph can be disconnceted as well
    for (int i = 0; i < n; i += 1)
    {
        if (colored[i] == -1)
        {
            // This means this is not visited as it is not colored yet
            ans = ans && f(i, n, m, mat, colored);
            if (ans == false)
            {
                return "NO";
            }
        }
    }
    return "YES";
}