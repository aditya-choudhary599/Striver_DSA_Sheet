// Question Link : https://www.codingninjas.com/studio/problems/minimum-number-of-platforms_799400?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

// This solution is inspired by the solution video of this question given by striver

#include <bits/stdc++.h>
using namespace std;

int calculateMinPatforms(int at[], int dt[], int n)
{
    sort(at, at + n);
    sort(dt, dt + n);

    int maxi = 1, curr = 1;
    int i = 1, j = 0;
    while (i < n)
    {
        while (dt[j] < at[i])
        {
            j += 1;
            curr -= 1;
        }
        curr += 1;
        maxi = max(maxi, curr);
        i += 1;
    }
    return maxi;
}