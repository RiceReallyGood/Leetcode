#include <vector>
#include <queue>
using namespace std;
class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) :visited(0){
        dfs(nestedList);
    }

    int next() {
        return flattened[visited++];
    }

    bool hasNext() {
        return visited != flattened.size();
    }
private:
    void dfs(const vector<NestedInteger> &nestedList){
        for(int i = 0; i < nestedList.size(); i++){
            if(nestedList[i].isInteger())
                flattened.push_back(nestedList[i].getInteger());
            else
                dfs(nestedList[i].getList());
        }
    }
    vector<int> flattened;
    int visited;
};

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) :visited(0){
        dfs(nestedList);
    }

    int next() {
        int ret = flattened.front();
        flattened.pop();
        return ret;
    }

    bool hasNext() {
        return !flattened.empty();
    }
private:
    void dfs(const vector<NestedInteger> &nestedList){
        for(int i = 0; i < nestedList.size(); i++){
            if(nestedList[i].isInteger())
                flattened.push(nestedList[i].getInteger());
            else
                dfs(nestedList[i].getList());
        }
    }
    queue<int> flattened;
    int visited;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) : s(nestedList.rbegin(), nestedList.rend()) { helper(); }

    int next() {
        int ret = s.back().getInteger();
        s.pop_back();
        helper();
        return ret;
    }

    bool hasNext() { return !s.empty(); }
private:
    void helper(){
        while(!s.empty() && !s.back().isInteger()){
            vector<NestedInteger> last = s.back().getList();
            s.pop_back();
            for(auto it = last.rbegin(); it != last.rend(); it++)
                s.push_back(*it);
        }
    }
    vector<NestedInteger> s;
};