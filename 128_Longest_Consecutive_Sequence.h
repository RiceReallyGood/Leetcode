#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> index;
        int elements = 0;
        for (int num : nums) {
            if (index.find(num) == index.end()) {
                index.insert({num, elements++});
            }
        }

        UnionFind uf(elements);

        for (auto it : index) {
            int num = it.first;

            auto next = index.find(num + 1);
            if (next != index.end()) {
                uf.unionPair(it.second, next->second);
            }
        }

        int maxGroupSize = 0;
        for (int i = 0; i < elements; i++) {
            int groupSize = uf.groupSize(i);
            maxGroupSize = maxGroupSize < groupSize ? groupSize : maxGroupSize;
        }

        return maxGroupSize;
    }

private:
    class UnionFind {
    public:
        UnionFind(int size) : size_(size), parent(size), groupSize_(size) {
            for (int i = 0; i < size; i++) {
                parent[i] = i;
                groupSize_[i] = 1;
            }
        }
        void unionPair(int p, int q) {
            int pRoot = root(p);
            int qRoot = root(q);
            
            if (pRoot != qRoot) {
                if (groupSize_[pRoot] < groupSize_[qRoot]) {
                    parent[pRoot] = qRoot;
                    groupSize_[qRoot] += groupSize_[pRoot];
                } else {
                    parent[qRoot] = pRoot;
                    groupSize_[pRoot] += groupSize_[qRoot];
                }
            }
        }

        int groupSize(int p) {
            return groupSize_[root(p)];
        }
    
    private:
        int root(int p) {
            if (p != parent[p]) {
                parent[p] = root(parent[p]);
            }
            return parent[p];
        }

        int size_;
        vector<int> parent;
        vector<int> groupSize_;
    };
};