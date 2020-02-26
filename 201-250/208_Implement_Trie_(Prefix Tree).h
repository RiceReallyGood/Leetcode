#include <vector>
#include <string>
#include <map>
using namespace std;

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() { root = new TreeNode(); }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TreeNode *p = root;
        for(int i = 0; i < word.length(); i++){
            int index = word[i] - 'a';
            if(p->next[index] == nullptr)
                p->next[index] = new TreeNode();
            p = p->next[index];
        }
        p->isword = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TreeNode *p = root;
        for(int i = 0; i < word.length(); i++){
            int index = word[i] - 'a';
            if(p->next[index] == nullptr)
                return false;
            p = p->next[index];
        }
        return p->isword;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TreeNode *p = root;
        for(int i = 0; i < prefix.length(); i++){
            int index = prefix[i] - 'a';
            if(p->next[index] == nullptr)
                return false;
            p = p->next[index];
        }
        return true;
    }

private:
    class TreeNode{
      public:
        TreeNode(bool _isword = false) : isword(_isword), next(26, nullptr) {}
        bool isword;
        vector<TreeNode*> next;
    };

    TreeNode *root;
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() { root = new TreeNode(); }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TreeNode *p = root;
        for(int i = 0; i < word.length(); i++){
            if((p->next).find(word[i]) == (p->next).end())
                (p->next)[word[i]] = new TreeNode();
            p = (p->next)[word[i]];
        }
        p->isword = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TreeNode *p = root;
        for(int i = 0; i < word.length(); i++){
            if((p->next).find(word[i]) == (p->next).end())
                return false;
            p = (p->next)[word[i]];
        }
        return p->isword;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TreeNode *p = root;
        for(int i = 0; i < prefix.length(); i++){
            if((p->next).find(prefix[i]) == (p->next).end())
                return false;
            p = (p->next)[prefix[i]];
        }
        return true;
    }

private:
    class TreeNode{
      public:
        TreeNode(bool _isword = false) : isword(_isword) {}
        bool isword;
        map<char, TreeNode*> next;
    };

    TreeNode *root;
};


class Trie {
public:
    /** Initialize your data structure here. */
    Trie() { root = new TreeNode(); }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TreeNode *p = root;
        for(int i = 0; i < word.length(); i++){
            int index = word[i] - 'a';
            if(p->next[index] == nullptr)
                p->next[index] = new TreeNode();
            p = p->next[index];
        }
        p->isword = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TreeNode *p = root;
        for(int i = 0; i < word.length(); i++){
            int index = word[i] - 'a';
            if(p->next[index] == nullptr)
                return false;
            p = p->next[index];
        }
        return p->isword;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TreeNode *p = root;
        for(int i = 0; i < prefix.length(); i++){
            int index = prefix[i] - 'a';
            if(p->next[index] == nullptr)
                return false;
            p = p->next[index];
        }
        return true;
    }

private:
    class TreeNode{
      public:
        TreeNode(bool _isword = false) : isword(_isword) {
            for(int i = 0; i < 26; i++) 
                next[i] = nullptr;
        }
        bool isword;
        TreeNode* next[26];
    };

    TreeNode *root;
};