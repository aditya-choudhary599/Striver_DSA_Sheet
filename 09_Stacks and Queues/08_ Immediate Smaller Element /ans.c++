// Question Link : https://www.codingninjas.com/studio/problems/immediate-smaller-element-_1062597?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <bits/stdc++.h>
using namespace std;

void immediateSmaller(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n - 1; i += 1)
    {
        if (a[i + 1] < a[i])
        {
            a[i] = a[i + 1];
        }
        else
        {
            a[i] = -1;
        }
    }
    a[n - 1] = -1;
    return;
}
