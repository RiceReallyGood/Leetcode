#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        vector<int> ps;
        return recurse(root, sum, ps);
    }

private:
    int recurse(TreeNode* root, int sum ,vector<int>& ps){
        if(!root) return 0;
        int ret = 0;
        if(root->val == sum) ret = 1;
        for(int i = 0; i < ps.size(); i++){
            ps[i] += root->val;
            if(ps[i] == sum) ret++;
        }
        ps.push_back(root->val);
        ret += recurse(root->left, sum, ps) + recurse(root->right, sum, ps);
        for(int i = 0; i < ps.size() - 1; i++)
            ps[i] -= root->val;
        ps.pop_back();
        return ret;
    }
};