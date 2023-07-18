// Question Link : https://www.codingninjas.com/studio/problems/min-heap_4691801?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
public:
    vector<int> bucket;

    void up_heapify(int pos)
    {
        if (pos == 0)
        {
            return;
        }

        int child_idx = pos;
        int parent_idx = (child_idx - 1) / 2;

        if (this->bucket[parent_idx] > this->bucket[child_idx])
        {
            swap(this->bucket[parent_idx], this->bucket[child_idx]);
            up_heapify(parent_idx);
        }

        return;
    }

    void insert_into_MinHeap(int x)
    {
        this->bucket.push_back(x);
        up_heapify(this->bucket.size() - 1);
        return;
    }

    void down_heapify(int pos)
    {
        if (pos >= this->bucket.size())
        {
            return;
        }

        int parent_idx = pos;
        int left_child_idx = 2 * pos + 1;
        int right_child_idx = 2 * pos + 2;

        int left_child_element = INT_MAX, right_child_element = INT_MAX;

        if (left_child_idx < this->bucket.size())
        {
            left_child_element = this->bucket[left_child_idx];
        }
        if (right_child_idx < this->bucket.size())
        {
            right_child_idx = this->bucket[right_child_idx];
        }

        if (left_child_element <= right_child_element && this->bucket[parent_idx] > left_child_element)
        {
            swap(this->bucket[parent_idx], this->bucket[left_child_idx]);
            down_heapify(left_child_idx);
        }

        else if (left_child_element >= right_child_element && this->bucket[parent_idx] > right_child_element)
        {
            swap(this->bucket[parent_idx], this->bucket[right_child_idx]);
            down_heapify(right_child_idx);
        }

        return;
    }

    int pop_from_MinHeap()
    {
        if (this->bucket.size() == 0)
        {
            return -1;
        }
        int ans = this->bucket[0];
        this->bucket[0] = this->bucket[this->bucket.size() - 1];
        this->bucket.pop_back();
        down_heapify(0);
        return ans;
    }
};

vector<int> minHeap(int n, vector<vector<int>> &q)
{
    MinHeap mihp;
    int m = q.size();
    vector<int> op;
    for (int i = 0; i < m; i += 1)
    {
        if (q[i].size() == 2)
        {
            mihp.insert_into_MinHeap(q[i][1]);
        }
        else
        {
            int ans = mihp.pop_from_MinHeap();
            op.push_back(ans);
        }
    }

    return op;
}
