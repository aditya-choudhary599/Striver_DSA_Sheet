// Question Link : https://www.codingninjas.com/studio/problems/max-of-min_982935?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;
vector<int> maxMinWindow(vector<int> arr, int n)
{

    vector<int> ans;
    for (int window_size = 1; window_size <= n; window_size += 1)
    {
        int maxi = INT_MIN;
        for (int i = 0; i <= n - window_size; i += 1)
        {
            maxi = max(maxi, *min_element(arr.begin() + i, arr.begin() + i + window_size));
        }
        ans.push_back(maxi);
    }

    return ans;
}