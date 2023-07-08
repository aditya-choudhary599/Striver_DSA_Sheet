// Question Link : https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

// TC : 0(N)
// SC : 0(N)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        int left = 0, right = 0, ans = 0;
        set<char> st;
        while (right < n)
        {
            if (st.empty() == true)
            {
                st.insert(s[right]);
                right += 1;
                continue;
            }

            ans = max(ans, right - left);

            int prev = st.size();
            st.insert(s[right]);
            int after = st.size();

            if (prev == after)
            {
                while (s[left] != s[right])
                {
                    st.erase(s[left]);
                    left += 1;
                }
                left += 1;
                right += 1;
            }
            else
            {
                right += 1;
            }
        }
        ans = max(ans, right - left);
        return ans;
    }
};