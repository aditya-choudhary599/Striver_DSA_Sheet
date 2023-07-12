// Question Link : https://www.codingninjas.com/studio/problems/job-sequencing-problem_1169460?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

// This solution algorithm is as per the best solution algorithm explained by striver in his solution vido of this problem

#include <bits/stdc++.h>
using namespace std;

int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    int n = jobs.size();
    priority_queue<vector<int>> pq;
    for (int i = 0; i < n; i += 1)
    {
        pq.push({jobs[i][1], jobs[i][0]});
    }

    int ans = 0;
    vector<int> time(3001, -1);

    while (pq.empty() != true)
    {
        vector<int> top = pq.top();
        pq.pop();

        int i = top[1] - 1;
        while (i >= 0 && time[i] != -1)
        {
            i -= 1;
        }
        if (i >= 0)
        {
            time[i] = top[0];
            ans += top[0];
        }
    }
    return ans;
}
