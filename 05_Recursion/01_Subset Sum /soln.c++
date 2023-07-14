// Question Link : https://www.codingninjas.com/studio/problems/subset-sum_3843086?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

vector<int> f(int index, int n, vector<int> &nums)
{
    if (index == n)
    {
        return {0};
    }
    vector<int> small_ans = f(index + 1, n, nums);
    int m = small_ans.size();
    for (int i = 0; i < m; i += 1)
    {
        small_ans.push_back(small_ans[i] + nums[index]);
    }
    
    // So now small ans contain the pick as well not pick sum also
    return small_ans;
}

vector<int> subsetSum(vector<int> &nums)
{
    vector<int> ans = f(0, nums.size(), nums);
    sort(ans.begin(), ans.end());
    return ans;
}
