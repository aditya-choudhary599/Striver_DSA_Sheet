// Question Link : https://www.codingninjas.com/studio/problems/merge-k-sorted-arrays_975379?leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    vector<int> ans;
    for (int i = 0; i < k; i += 1)
    {
        ans.insert(ans.end(), kArrays[i].begin(), kArrays[i].end());
    }
    sort(ans.begin(), ans.end());
    return ans;
}
