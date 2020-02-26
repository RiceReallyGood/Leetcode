#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++){
            if(nums[i] == 0)
                visited[i] = true;
            if(visited[i]) continue;
            int dir = nums[i] > 0 ? 1 : -1;
            unordered_set<int> indices;
            int idx = i;
            while(indices.find(idx) == indices.end()){
                if(visited[idx] || (dir > 0 && nums[idx] < 0) || (dir < 0 && nums[idx] > 0))    
                    break;
                indices.insert(idx);
                idx = (idx + nums[idx]) % n;
                if(idx < 0)
                    idx += n;
            }
            if(indices.size() > 1 && indices.find(idx) != indices.end() && ((idx + nums[idx]) % n + n) % n != idx)
                return true;
            for(auto it = indices.begin(); it != indices.end(); it++)
                visited[*it] = true;
        }
        return false;
    }
};

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++){
            if(nums[i] == 0)
                visited[i] = true;
            if(visited[i]) continue;
            int dir = nums[i] > 0 ? 1 : -1;
            int fast = i, slow = i;
            do{
                if(visited[fast] || (dir > 0 && nums[fast] < 0) || (dir < 0 && nums[fast] > 0))
                    break;
                fast = (fast + nums[fast]) % n;
                if(fast < 0) fast += n;
                if(visited[fast] || (dir > 0 && nums[fast] < 0) || (dir < 0 && nums[fast] > 0))
                    break;
                fast = (fast + nums[fast]) % n;
                if(fast < 0) fast += n;
                
                slow = (slow + nums[slow]) % n;
                if(slow < 0) slow += n;
            }while(fast != slow);
            if(fast == slow && (((fast + nums[fast]) % n) + n) % n != fast)
                return true;
            
            slow = i;
            while(slow != fast){
                visited[slow] = true;
                slow = (slow + nums[slow]) % n;
                if(slow < 0) slow += n;
            }
            if((((fast + nums[fast]) % n) + n) % n == fast)
                visited[fast] = true;
        }
        return false;
    }
};