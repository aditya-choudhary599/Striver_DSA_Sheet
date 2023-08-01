// Question Link : https://www.codingninjas.com/studio/problems/trie-delete-operation_1062663?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

class TrieNode
{ // Definition of TrieNode class
public:
    TrieNode *children[26];
    bool isEnd;
    TrieNode()
    {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }

    TrieNode *deleteWord(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            root->isEnd = false;
            return root;
        }

        if (root->children[word[0] - 'a'] != NULL)
        {
            return deleteWord(root->children[word[0] - 'a'], word.substr(1));
        }
        else
        {
            return NULL;
        }
    }
};
