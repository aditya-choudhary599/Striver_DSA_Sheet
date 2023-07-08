// Question Link : https://leetcode.com/problems/powx-n/description/

// TC : 0(log(N))
// SC : 0(1)

// This technique was taught by the striver in his solution video of this question.

// This technique used here is called as binary exponention technique

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    double f(double x,int n)
    {
        if(n==0)
        {
            return 1.0;
        }

        if(n%2==0)
        {
            return f(x*x,n/2);
        }
        else
        {
            return x*f(x,n-1);
        }
    }   

    double myPow(double x, int n) {
        if(n<0)
        {
            return 1.0/myPow(x,abs(n-0));
        }
        return f(x,n);
    }
};