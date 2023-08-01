// Question Link : https://www.codingninjas.com/studio/problems/1062667?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

void f(int index, int n, vector<int> &vec, vector<vector<int>> &ans, vector<int> &v)
{
    ans.push_back(vec);
    if (index == n)
    {
        return;
    }

    int i = index;
    while (i < n)
    {
        vec.push_back(v[i]);
        f(i + 1, n, vec, ans, v);
        vec.pop_back();

        i += 1;
        while (i < n && v[i] == v[i - 1])
        {
            i += 1;
        }
    }
    return;
}

vector<vector<int>> pwset(vector<int> v)
{
    sort(v.begin(), v.end());
    vector<vector<int>> ans;
    vector<int> vec;
    f(0, v.size(), vec, ans, v);
    return ans;
}