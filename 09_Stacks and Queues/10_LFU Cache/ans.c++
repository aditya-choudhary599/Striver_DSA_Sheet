// Question Link : https://leetcode.com/problems/lfu-cache/description/

#include <bits/stdc++.h>
using namespace std;

class LFUCache
{
public:
    map<int, vector<int>> freq;
    map<int, pair<int, int>> mp;

    // here in mp the key will be key and value will be a pair which has (value,current_frequency)

    int capacity;

    LFUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end())
        {
            // This means key is not present in the data structure
            return -1;
        }

        // This means key is present in the data structure
        int op = mp[key].first;

        // Before returning we have to update its frequency

        // Step 1 : Erasing its original entries
        vector<int> curr_freq_vec = freq[mp[key].second];
        curr_freq_vec.erase(find(curr_freq_vec.begin(), curr_freq_vec.end(), key));
        freq[mp[key].second] = curr_freq_vec;

        // Step 2 : Updating its frequency
        mp[key].second += 1;

        // Step 3 : Making changes in the freq table
        vector<int> new_freq_vec = freq[mp[key].second];
        new_freq_vec.push_back(key);
        freq[mp[key].second] = new_freq_vec;

        return op;
    }

    void put(int key, int value)
    {
        if (mp.find(key) == mp.end())
        {
            // This means key is not present in the data structure
            if (mp.size() < capacity)
            {
                // Making new key-value pair and setting its intial frequency to 1
                mp[key] = {value, 1};
                freq[1].push_back(key);
                return;
            }
            else
            {
                // Deleting the least freuently used key
                int key_to_delete = -1;
                for (int i = 1; i < 100000; i += 1)
                {
                    if (freq[i].size() != 0)
                    {
                        key_to_delete = freq[i][0];
                        freq[i].erase(freq[i].begin());
                        break;
                    }
                }
                mp.erase(key_to_delete);

                // Making new key-value pair and setting its intial frequency to 1
                mp[key] = {value, 1};
                freq[1].push_back(key);
                return;
            }
        }
        else
        {
            // This means key is present in the data structure

            // Step 1 : Erasing its original entries
            vector<int> curr_freq_vec = freq[mp[key].second];
            curr_freq_vec.erase(find(curr_freq_vec.begin(), curr_freq_vec.end(), key));
            freq[mp[key].second] = curr_freq_vec;

            // Step 2 : Updating its frequency
            mp[key].second += 1;
            mp[key].first = value;

            // Step 3 : Making changes in the freq table
            vector<int> new_freq_vec = freq[mp[key].second];
            new_freq_vec.push_back(key);
            freq[mp[key].second] = new_freq_vec;

            return;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */