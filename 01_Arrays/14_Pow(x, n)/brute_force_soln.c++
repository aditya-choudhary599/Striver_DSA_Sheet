// Question Link : https://leetcode.com/problems/powx-n/description/

// TC : 0(N)
// SC : 0(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n<0)
        {
            return 1/myPow(x,abs(n-0));
        }
        double ans = 1.0;
        for (int i = 0; i <n; i++) {
            ans = ans * x;
        }
        return ans;
    }
};