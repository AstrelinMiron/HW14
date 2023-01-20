#pragma once
#include <string>

const int ALPHABET_SIZE = 33;

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

    /* ��������� ���� � ������, ���� ��� ���,
     ����� ���� ���� ������� �������� ���� ������ 
     �������� ��������� �������� �.�. ����� �����*/
    void insertKey(const std::string& key);

    // ������� ������
    void cleanTrie(void);

    // ���������� true ���� ���� ���� � ������, ����� false 
    bool searchKey(const std::string& key, bool printFlag);

    // ����������� ������� �������� ����� �� ������ 
    void removeKey(const std::string& key);

private:
    TrieNode _root;

    // ��������� ����� ���� � ������� ������
    TrieNode* getNewNode(void);


    void cleanInner(const TrieNode* pNode);

    // ���������� true ���� root ����� ����, ����� false
    bool isEmpty(TrieNode* pNode);

    // ����������� ������� �������� ����� �� ������
    TrieNode* removeInner(TrieNode* root, std::string key, int depth = 0);

    // ����� ��������� ����
    void printVariants(const TrieNode* pNode, const std::string& pre, std::string& post);
};
