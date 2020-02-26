#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> paths;
        unordered_set<string> Unvisited(wordList.begin(), wordList.end());
        if(Unvisited.find(endWord) == Unvisited.end())
            return paths;
        
        int wl = beginWord.length();
        
        TreeNode *root = new TreeNode(beginWord);
        queue<TreeNode*> Levelq;
        Levelq.push(root);

        bool found = false;
        while(!found && !Levelq.empty()){
            int levelsz = Levelq.size();
            unordered_set<string> toerase;
            for(int i = 0; i < levelsz; i++){
                TreeNode *p = Levelq.front();
                Levelq.pop();
                if(Onlyonediff(p->word, endWord)){
                    found = true;
                    p->NextWords.push_back(new TreeNode(endWord));
                    continue;
                }
                if(!found){
                    for(int i = 0; i < wl; i++){
                        string tryword = p->word;
                        for(char c = 'a'; c <= 'z'; c++){
                            tryword[i] = c;
                            if(Unvisited.find(tryword) != Unvisited.end()){
                                TreeNode *node = new TreeNode(tryword);
                                p->NextWords.push_back(node);
                                Levelq.push(node);
                                toerase.insert(tryword);
                            }
                        }
                    }
                }
            }
            for(string word : toerase)
                Unvisited.erase(word);
        }

        vector<string> path;
        WriteAllPaths(root, endWord, path, paths);
        return paths;
    }

private:
    struct TreeNode
    {
        string word;
        vector<TreeNode*> NextWords;
        TreeNode(string s) : word(s) {}
    };
    bool Onlyonediff(const string& s1, const string& s2){
        int diff = 0;
        for(int i = 0; i < s1.size(); i++)
            if(s1[i] != s2[i])
                diff++;
        return diff == 1;
    }

    void WriteAllPaths(TreeNode* root,string& endWord ,vector<string> &path, vector<vector<string>> &paths){
        path.push_back(root->word);
        if(root->word == endWord)
            paths.push_back(path);
        for(TreeNode* tree : root->NextWords)
            WriteAllPaths(tree, endWord, path, paths);    
        path.pop_back();
    }
};

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> paths;
        unordered_set<string> Unvisited(wordList.begin(), wordList.end());
        if(Unvisited.find(endWord) == Unvisited.end())
            return paths;
        
        unordered_set<string> BeginSet;
        BeginSet.insert(beginWord);
        Unvisited.erase(beginWord);
        unordered_set<string> Endset;
        Endset.insert(endWord);
        Unvisited.erase(endWord);
        bool swaped = false;
        unordered_map<string,unordered_set<string>> next;

        int wl = beginWord.length();
        
        bool found = false;
        while(!found && !BeginSet.empty() && !Endset.empty()){
            if(BeginSet.size() > Endset.size()){
                BeginSet.swap(Endset);
                swaped = !swaped;
            }

            unordered_set<string> NextLevel;
            vector<string> toerase;
            for(string word : BeginSet){
                for(int i = 0; i < wl; i++){
                    string tryword = word;
                    for(char c = 'a'; c <= 'z'; c++){
                        if(c == word[i]) continue;

                        tryword[i] = c;
                        if(Endset.find(tryword) != Endset.end()){
                            found = true;
                            update(next, swaped, word, tryword);
                        }
                        else if(Unvisited.find(tryword) != Unvisited.end()){
                            NextLevel.insert(tryword);
                            toerase.push_back(tryword);
                            update(next, swaped, word, tryword);
                        }
                    }
                }
            }
            for(string word : toerase)
                Unvisited.erase(word);
            BeginSet.swap(NextLevel);
        }
        vector<string> path;
        GeneratePaths(next,beginWord,endWord,path,paths);
        return paths;
    }

private:
    void update(unordered_map<string,unordered_set<string>>& next, bool swaped,string word, string tryword){
        if(swaped)
            next[tryword].insert(word);
        else
            next[word].insert(tryword);
    }

    void GeneratePaths(unordered_map<string,unordered_set<string>>& next, string beginword, string &endword,vector<string> &path,vector<vector<string>>& paths){
        path.push_back(beginword);
        if(beginword == endword)
            paths.push_back(path);
        
        if(next.find(beginword) != next.end())
            for(string nextword : next[beginword])
                GeneratePaths(next, nextword, endword, path, paths);
        
        path.pop_back();
    }
};