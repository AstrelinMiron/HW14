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

    /* Вставляет ключ в дерево, если его нет,
     иначе если ключ явлется префксом узла дерева 
     помечает вкачестве литового т.е. конец слова*/
    void insertKey(const std::string& key);

    // Очистка дерева
    void cleanTrie(void);

    // Возврашает true если ключ есть в дереве, иначе false 
    bool searchKey(const std::string& key, bool printFlag);

    // Рекурсивная функция удаления ключа из дерева 
    void removeKey(const std::string& key);

private:
    TrieNode _root;

    // Возвращет новый узел с пустыми детьми
    TrieNode* getNewNode(void);


    void cleanInner(const TrieNode* pNode);

    // Возвращает true если root имеет лист, иначе false
    bool isEmpty(TrieNode* pNode);

    // Рекурсивная функция удаления ключа из дерева
    TrieNode* removeInner(TrieNode* root, std::string key, int depth = 0);

    // Вывод вариантов слов
    void printVariants(const TrieNode* pNode, const std::string& pre, std::string& post);
};
