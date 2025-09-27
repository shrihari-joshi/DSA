#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;

    bool ContainsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    void increaseEnd() { cntEndWith++; }
    void deleteEnd() { cntEndWith--; }
    void increasePrefix() { cntPrefix++; }
    void reducePrefix() { cntPrefix--; }
};
class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->ContainsKey(word[i]))
                node->put(word[i], new Node());

            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }
    int countWordsEqual(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->ContainsKey(word[i]))
                return 0;
            node = node->get(word[i]);
        }
        return node->cntEndWith;
    }
    int countWordsStartingWith(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->ContainsKey(word[i]))
                return 0;
            node = node->get(word[i]);
        }
        return node->cntPrefix;
    }
    void erase(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->ContainsKey(word[i]))
                return;
            node = node->get(word[i]);
            node->reducePrefix();
        }
        node->deleteEnd();
    }
};