#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<bool> visited(wordList.size(), false);
        queue<int> wordlevel;
        int level = 1;
        wordlevel.push(-1);
        while(!wordlevel.empty()){
            level++;
            int wordnum = wordlevel.size();
            for(int i = 0; i < wordnum; i++){
                string curr = wordlevel.front() == -1 ? beginWord : wordList[wordlevel.front()];
                wordlevel.pop();
                for(int j = 0; j < wordList.size(); j++){
                    if(visited[j])
                        continue;
                    if(Onlyonediff(curr,wordList[j])){
                        if(wordList[j] == endWord)
                            return level;
                        visited[j] = true;
                        wordlevel.push(j);
                    }
                }
            }
        }
        return 0;
    }

private:
    bool Onlyonediff(const string& s1, const string& s2){
        int diff = 0;
        for(int i = 0; i < s1.size(); i++)
            if(s1[i] != s2[i])
                diff++;
        return diff == 1;
    }
};

class Solution2 {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(),wordList.end(),endWord) == wordList.end())
            return 0;
        
        unordered_set<int> unvisited;
        for(int i = 0; i < wordList.size(); i++)
            unvisited.insert(i);
        queue<int> wordlevel;
        int level = 1;
        wordlevel.push(-1);
        while(!wordlevel.empty()){
            level++;
            int wordnum = wordlevel.size();
            for(int i = 0; i < wordnum; i++){
                string curr = wordlevel.front() == -1 ? beginWord : wordList[wordlevel.front()];
                wordlevel.pop();
                vector<int> toerase;
                for(int index : unvisited){
                    if(Onlyonediff(curr,wordList[index])){
                        if(wordList[index] == endWord)
                            return level;
                        wordlevel.push(index);
                        toerase.push_back(index);
                    }
                }

                for(int index : toerase)
                    unvisited.erase(index);
            }
        }
        return 0;
    }

private:
    bool Onlyonediff(const string& s1, const string& s2){
        int diff = 0;
        for(int i = 0; i < s1.size(); i++)
            if(s1[i] != s2[i])
                diff++;
        return diff == 1;
    }
};

class Solution3 {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> Unvisited(wordList.begin(),wordList.end());
        if(Unvisited.find(endWord) == Unvisited.end())
            return 0;
        int wl = beginWord.length();
        int level = 1;
        unordered_set<string> BeginSet;
        unordered_set<string> EndSet;
        BeginSet.insert(beginWord);
        EndSet.insert(endWord);

        while(!BeginSet.empty() && !EndSet.empty()){
            level++;
            if(BeginSet.size() > EndSet.size())
                BeginSet.swap(EndSet);
            
            unordered_set<string> NextLevelSet;
            for(string word : BeginSet){
                for(int i = 0; i < wl; i++){
                    string tryword = word;
                    for(char c = 'a'; c <= 'z'; c++){
                        tryword[i] = c;
                        if(EndSet.find(tryword) != EndSet.end())
                            return level;
                        if(Unvisited.find(tryword) != Unvisited.end()){
                            NextLevelSet.insert(tryword);
                            Unvisited.erase(tryword);
                        }
                    }
                }
            }
            BeginSet.swap(NextLevelSet);
        }
        
        return 0;
    }
};