// Question Link : https://leetcode.com/problems/find-k-closest-elements/description/

#include<bits/stdc++.h>

class Solution {
public:
    std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x) {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, CustomComparator> pq;

        for (int num : arr) {
            pq.push({abs(num - x), num});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        std::vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        std::sort(result.begin(),result.end());

        return result;
    }

private:
    struct CustomComparator {
        bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) const {
            if (a.first != b.first) {
                return a.first < b.first; // Closer distance comes first
            }
            return a.second < b.second; // If distances are equal, smaller number comes first
        }
    };
};

