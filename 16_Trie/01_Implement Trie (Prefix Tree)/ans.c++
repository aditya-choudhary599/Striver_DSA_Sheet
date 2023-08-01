// Question Link : https://leetcode.com/problems/implement-trie-prefix-tree/description/

#include <bits/stdc++.h>
using namespace std;

class Trie_Node
{
public:
    char ch;
    unordered_map<char, Trie_Node *> children;
    bool is_end;

    Trie_Node(char ch)
    {
        this->ch = ch;
        this->is_end = false;
        return;
    }
};

class Trie
{
public:
    Trie_Node *root;
    Trie()
    {
        this->root = new Trie_Node('#');
    }

    void helper_insert(Trie_Node *root, string word)
    {
        int n = word.length();
        if (n == 0)
        {
            root->is_end = true;
            return;
        }
        char curr_char = word[0];
        if (root->children.find(curr_char) == root->children.end())
        {
            root->children[curr_char] = new Trie_Node(curr_char);
            helper_insert(root->children[curr_char], word.substr(1));
            return;
        }
        else
        {
            helper_insert(root->children[curr_char], word.substr(1));
            return;
        }
    }

    void insert(string word)
    {
        helper_insert(this->root, word);
        return;
    }

    bool helper_search(Trie_Node *root, string word)
    {
        int n = word.length();
        if (n == 0)
        {
            if (root->is_end == true)
            {
                return true;
            }
            return false;
        }
        char curr_char = word[0];
        if (root->children.find(curr_char) == root->children.end())
        {
            return false;
        }
        return helper_search(root->children[curr_char], word.substr(1));
    }

    bool search(string word)
    {
        char first_char = word[0];
        if (this->root->children.find(first_char) == this->root->children.end())
        {
            return false;
        }
        return helper_search(this->root->children[first_char], word.substr(1));
    }

    bool helper_starts_with(Trie_Node *root, string word)
    {
        int n = word.length();
        if (n == 0)
        {
            return true;
        }
        char curr_char = word[0];
        if (root->children.find(curr_char) == root->children.end())
        {
            return false;
        }
        return helper_starts_with(root->children[curr_char], word.substr(1));
    }

    bool startsWith(string word)
    {
        char first_char = word[0];
        if (this->root->children.find(first_char) == this->root->children.end())
        {
            return false;
        }
        return helper_starts_with(this->root->children[first_char], word.substr(1));
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */