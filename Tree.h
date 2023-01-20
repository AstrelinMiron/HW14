#pragma once
#include <string>

const int ALPHABET_SIZE = 26;

struct TrieNode
{
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
};

class Trie
{
public:
    Trie();
    ~Trie();

    /* Inserts a key into the tree, if it does not exist,
      else if the key is a tree node prefix
      marks as EOW, i.e. the end of a word*/
    void insertKey(const std::string& key);

    // tree cleaning
    void cleanTrie(void);

    // Returns true if the key is in the tree, otherwise false 
    bool searchKey(const std::string& key, bool printFlag);

    // Recursive function to remove a key from a tree 
    void removeKey(const std::string& key);

private:
    TrieNode _root;

    // Returns a new node with empty children
    TrieNode* getNewNode(void);

    void cleanInner(const TrieNode* pNode);

    // Returns true if root has a leaf, otherwise false
    bool isEmpty(TrieNode* pNode);

    // Recursive function to remove a key from a tree
    TrieNode* removeInner(TrieNode* root, std::string key, int depth = 0);

    // Output of word variants
    void printVariants(const TrieNode* pNode, const std::string& pre, std::string& post);
};
