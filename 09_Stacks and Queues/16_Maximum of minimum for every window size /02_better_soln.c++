// Question Link : https://www.codingninjas.com/studio/problems/max-of-min_982935?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

vector<int> maxMinWindow(vector<int> arr, int n)
{
    vector<int> ans;
    vector<int> prev;
    for (int i = 1; i <= n; i += 1)
    {
        if (prev.size() == 0)
        {
            prev = arr;
            ans.push_back(*max_element(arr.begin(), arr.end()));
        }
        else
        {
            vector<int> temp;
            int k = prev.size();
            int maxi = INT_MIN;
            for (int j = 0; j < k - 1; j += 1)
            {
                temp.push_back(min(prev[j], prev[j + 1]));
                maxi = max(maxi, min(prev[j], prev[j + 1]));
            }

            prev = temp;
            ans.push_back(maxi);
        }
    }

    return ans;
}