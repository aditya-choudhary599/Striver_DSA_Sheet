// Question Link : https://leetcode.com/problems/find-median-from-data-stream/description/

// Solution Reference Link : https://www.youtube.com/watch?v=1LkOrc-Le-Y&t=1232s

#include<bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    priority_queue<int> max_heap;
    priority_queue<int,vector<int>,greater<int>> min_heap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(max_heap.empty()==true)
        {
            max_heap.push(num);
            return;
        }
        if(max_heap.size()==min_heap.size())
        {
            // This means we should insert our element in the max heap now after some filterations in it.
            if(num<=min_heap.top())
            {
                max_heap.push(num);
            }
            else
            {
                max_heap.push(min_heap.top());
                min_heap.pop();
                min_heap.push(num);
            }
        }
        else
        {
            // This means we should insert our element in the min heap now after some filtertions in it
            if(num>=max_heap.top())
            {
                min_heap.push(num);
            }
            else
            {
                min_heap.push(max_heap.top());
                max_heap.pop();
                max_heap.push(num);
            }
        }
    }
    
    double findMedian() {
        if(max_heap.size()==min_heap.size())
        {
            return ((max_heap.top()+min_heap.top())*1.0)/2;
        }
        else
        {
            return max_heap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */