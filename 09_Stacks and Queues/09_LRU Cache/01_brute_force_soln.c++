// Question Link : https://leetcode.com/problems/lru-cache/'

#include <bits/stdc++.h>
using namespace std;

class LRUCache
{

private:
    queue<pair<int, int>> q;
    unordered_map<int, int> mp;
    int capacity;

    void helper_delete(int key)
    {
        vector<pair<int, int>> temp;
        while (q.empty() != true)
        {
            temp.push_back(q.front());
            q.pop();
        }
        int n = temp.size();
        for (int i = 0; i < n; i += 1)
        {
            if (temp[i].first != key)
            {
                q.push(temp[i]);
            }
        }

        return;
    }

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        return;
    }

    int get(int key)
    {
        if (mp.find(key) != mp.end())
        {
            // Need to make changes in que again
            helper_delete(key);
            q.push({key, mp[key]});

            return mp[key];
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (mp.find(key) == mp.end())
        {
            // This means this key-value pair is not present in the data structure
            if (mp.size() < capacity)
            {
                q.push({key, value});
                mp[key] = value;
                return;
            }
            else
            {
                // Getting the key of the least recently used key-value pair to be deleted
                int key_to_delete = q.front().first;

                // Deleteing the least recently used key-value pair
                q.pop();
                mp.erase(key_to_delete);

                // Inserting new key-value pair
                q.push({key, value});
                mp[key] = value;
                return;
            }
        }
        else
        {
            // This means the key already exists in the data structure

            // First of all delete that key-value pair entry from the queue
            helper_delete(key);

            // Now adding the new_entry
            q.push({key, value});
            mp[key] = value;
            return;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */