// Question Link : https://leetcode.com/problems/kth-largest-element-in-a-stream/

#include<bits/stdc++.h>
using namespace std;

class KthLargest {
    private:
        std::vector<int> arr;
        int k_val;

    public:
        KthLargest(int k, std::vector<int>& nums) {
            arr = nums;
            std::sort(arr.begin(), arr.end());
            k_val = k;
        }

        int add(int val) {
            arr.push_back(val);
            int i = arr.size() - 1;
            while (i > 0) {
                if (arr[i] <= arr[i-1]) {
                    std::swap(arr[i], arr[i-1]);
                    i--;
                } else {
                    break;
                }
            }
            return arr[arr.size()-k_val];
        }
};
