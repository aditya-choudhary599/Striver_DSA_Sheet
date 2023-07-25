// Question Link : https://www.codingninjas.com/studio/problems/893000?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

// Observation

int minCharsforPalindrome(string str)
{
    int n = str.length();
    if (n == 1)
    {
        return 0;
    }
    if (n == 2 && str[1] == str[0])
    {
        return 0;
    }
    if (n == 2 && str[1] != str[0])
    {
        return 1;
    }
    if (n % 2 == 0)
    {
        int mid = n / 2;
        int mini = INT_MAX;
        for (int i = 0; i < mid; i += 1)
        {
            // For odd length
            int l = i, r = i;
            while (l >= 0 && r < n && str[l] == str[r])
            {
                l -= 1;
                r += 1;
            }
            if (l < 0 && r >= n)
            {
                // Already palindorme
                return 0;
            }
            else if (l < 0 && r < n)
            {
                mini = min(mini, n - r);
            }

            // For even length
            l = i;
            r = i + 1;
            while (l >= 0 && r < n && str[l] == str[r])
            {
                l -= 1;
                r += 1;
            }
            if (l < 0 && r >= n)
            {
                // Already palindorme
                return 0;
            }
            else if (l < 0 && r < n)
            {
                mini = min(mini, n - r);
            }
        }
        return mini;
    }
    else
    {
        int mid = n / 2;
        int mini = INT_MAX;
        for (int i = 0; i <= mid; i += 1)
        {
            // For odd length
            int l = i, r = i;
            while (l >= 0 && r < n && str[l] == str[r])
            {
                l -= 1;
                r += 1;
            }
            if (l < 0 && r >= n)
            {
                // Already palindorme
                return 0;
            }
            else if (l < 0 && r < n)
            {
                mini = min(mini, n - r);
            }

            // For even length
            l = i;
            r = i + 1;
            while (l >= 0 && r < n && str[l] == str[r])
            {
                l -= 1;
                r += 1;
            }
            if (l < 0 && r >= n)
            {
                // Already palindorme
                return 0;
            }
            else if (l < 0 && r < n)
            {
                mini = min(mini, n - r);
            }
        }
        return mini;
    }
}
