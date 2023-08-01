// Question Link : https://www.codingninjas.com/studio/problems/implement-trie_1387095?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Trie_Node
{
public:
    char ch;
    unordered_map<char, Trie_Node *> children;
    int prefix_cnt;
    int is_end;

    Trie_Node(char ch)
    {
        this->ch = ch;
        this->is_end = 0;
        this->prefix_cnt = 0;
        return;
    }
};

class Trie
{
    Trie_Node *root;

public:
    Trie()
    {
        this->root = new Trie_Node('#');
    }

    void helper_insert(Trie_Node *root, string word)
    {
        int n = word.length();
        if (n == 0)
        {
            root->is_end += 1;
            return;
        }
        char curr_char = word[0];
        if (root->children.find(curr_char) == root->children.end())
        {
            root->children[curr_char] = new Trie_Node(curr_char);
            root->children[curr_char]->prefix_cnt += 1;
            helper_insert(root->children[curr_char], word.substr(1));
            return;
        }
        else
        {
            root->children[curr_char]->prefix_cnt += 1;
            helper_insert(root->children[curr_char], word.substr(1));
            return;
        }
    }

    void insert(string &word)
    {
        helper_insert(root, word);
        return;
    }

    int helper_countWordsEqualTo(Trie_Node *root, string word)
    {
        int n = word.length();
        if (n == 0)
        {
            return root->is_end;
        }
        char curr_char = word[0];
        if (root->children.find(curr_char) == root->children.end())
        {
            return 0;
        }
        return helper_countWordsEqualTo(root->children[curr_char], word.substr(1));
    }

    int countWordsEqualTo(string &word)
    {
        return helper_countWordsEqualTo(root, word);
    }

    int helper_countWordsStartingWith(Trie_Node *root, string word)
    {
        int n = word.length();
        if (n == 0)
        {
            return root->prefix_cnt;
        }
        char curr_char = word[0];
        if (root->children.find(curr_char) == root->children.end())
        {
            return 0;
        }
        return helper_countWordsStartingWith(root->children[curr_char], word.substr(1));
    }

    int countWordsStartingWith(string &word)
    {
        return helper_countWordsStartingWith(root, word);
    }

    void helper_delete(Trie_Node *root, string word)
    {
        if (word.size() == 0)
        {
            if (root->is_end > 0)
            {
                root->is_end -= 1;
            }
            return;
        }

        char curr_char = word[0];
        if (root->children.find(curr_char) != root->children.end())
        {
            helper_delete(root->children[word[0]], word.substr(1));
            root->children[word[0]]->prefix_cnt -= 1;
        }
        else
        {
            return;
        }
    }

    void erase(string &word)
    {
        helper_delete(root, word);
    }
};
