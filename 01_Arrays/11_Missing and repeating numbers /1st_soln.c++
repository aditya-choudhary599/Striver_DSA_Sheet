// Question Link : https://www.codingninjas.com/studio/problems/873366?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include <bits/stdc++.h>
using namespace std;

pair<int, int> missingAndRepeating(vector<int> &vec, int n)
{
    vector<int> freq(n + 1, 0);
    for (int i = 0; i < n; i += 1)
    {
        freq[vec[i]] += 1;
    }

    pair<int, int> ans;
    for (int i = 1; i <= n; i += 1)
    {
        if (freq[i] == 0)
        {
            ans.first = i;
        }
        else if (freq[i] == 2)
        {
            ans.second = i;
        }
    }
    return ans;
}
