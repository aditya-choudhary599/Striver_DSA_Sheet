// Question Link : https://www.codingninjas.com/studio/problems/merge-k-sorted-arrays_975379?leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

vector<int> merge_two_sorted_arrays(vector<int> vec1, vector<int> vec2)
{
    int m = vec1.size(), n = vec2.size();
    vector<int> ans;
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (vec1[i] <= vec2[j])
        {
            ans.push_back(vec1[i]);
            i += 1;
        }
        else
        {
            ans.push_back(vec2[j]);
            j += 1;
        }
    }

    while (i < m)
    {
        ans.push_back(vec1[i]);
        i += 1;
    }

    while (j < n)
    {
        ans.push_back(vec2[j]);
        j += 1;
    }

    return ans;
}

vector<int> helper(int index, int k, vector<vector<int>> &kArrays)
{
    if (index == k - 1)
    {
        return kArrays[index];
    }
    vector<int> rcall = helper(index + 1, k, kArrays);
    return merge_two_sorted_arrays(kArrays[index], rcall);
}

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    return helper(0, k, kArrays);
}
