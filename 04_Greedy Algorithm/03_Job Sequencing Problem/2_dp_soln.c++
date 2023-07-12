// Question Link : https://www.codingninjas.com/studio/problems/job-sequencing-problem_1169460?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

int f(int index, int n, int curr_time, vector<vector<int>> &jobs)
{
    if (index == n)
    {
        return 0;
    }
    int not_pick = f(index + 1, n, curr_time, jobs);
    int pick = 0;
    if (curr_time < jobs[index][0])
    {
        pick = jobs[index][1] + f(index + 1, n, curr_time + 1, jobs);
    }
    return max(pick, not_pick);
}

int jobScheduling(vector<vector<int>> &jobs)
{
    int n = jobs.size();
    if (n == 1)
    {
        return jobs[0][1];
    }
    sort(jobs.begin(), jobs.end());
    // return f(0,n,0,jobs);

    vector<vector<int>> dp(n, vector<int>(3001, 0));

    for (int j = 0; j < jobs[n - 1][0]; j += 1)
    {
        dp[n - 1][j] = jobs[n - 1][1];
    }

    int ans = 0;
    for (int i = n - 2; i >= 0; i -= 1)
    {
        for (int j = 0; j < jobs[i][0]; j += 1)
        {
            int not_pick = dp[i + 1][j];
            int pick = jobs[i][1] + dp[i + 1][j + 1];
            dp[i][j] = max(pick, not_pick);
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}
