// Question Link : https://leetcode.com/problems/sort-colors/description/

// TC : 0(2N)
// SC : 0(1)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &vec)
    {
        int zero = 0, one = 0, two = 0;
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i] == 0)
            {
                zero++;
            }
            else if (vec[i] == 1)
            {
                one++;
            }
            else
            {
                two++;
            }
        }
        int i = 0;
        while (zero != 0)
        {
            vec[i] = 0;
            i++;
            zero--;
        }
        while (one != 0)
        {
            vec[i] = 1;
            i++;
            one--;
        }
        while (two != 0)
        {
            vec[i] = 2;
            i++;
            two--;
        }
    }
};