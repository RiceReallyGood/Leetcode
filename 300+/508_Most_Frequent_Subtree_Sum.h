#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> sum_freq;
        int maxfreq = 0;
        TreeSum(root, sum_freq, maxfreq);
        vector<int> ret;
        for(auto it : sum_freq)
            if(it.second == maxfreq)
                ret.push_back(it.first);
        return ret;
    }

private:
    int TreeSum(TreeNode* root, unordered_map<int, int>& sum_freq, int& maxfreq){
        if(!root) return 0;
        int sum = TreeSum(root->left, sum_freq, maxfreq) 
                + TreeSum(root->right, sum_freq, maxfreq) + root->val;
        sum_freq[sum]++;
        maxfreq = max(maxfreq, sum_freq[sum]);
        return sum;
    }
};