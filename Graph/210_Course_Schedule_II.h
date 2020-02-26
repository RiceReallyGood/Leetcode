#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<bool>> prs(numCourses, vector<bool>(numCourses, false));
        vector<int> prscount(numCourses, 0);
        for(auto v : prerequisites){
            prs[v[0]][v[1]] = true;
            prscount[v[0]]++;
        }
        vector<bool> visited(numCourses, false);
        vector<int> order;
        while(true){
            int course = 0;
            while(course < numCourses){
                if(visited[course] == false && prscount[course] == 0) break;
                course++;
            }
            if(course == numCourses) break;
            visited[course] = true;
            order.push_back(course);
            for(int i = 0; i < numCourses; i++){
                if(prs[i][course]){
                    prs[i][course] = false;
                    prscount[i]--;
                }
            }
        }
        if(order.size() == numCourses)
            return order;
        return vector<int>();
    }
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> prs(numCourses);
        for(auto& v : prerequisites)
            prs[v[0]].push_back(v[1]);
        
        vector<bool> determined(numCourses, false);
        vector<bool> path(numCourses, false);
        vector<int> order;
        for(int course = 0; course < numCourses; course++){
            if(!recurse(course, prs, determined, path, order))
                return vector<int>();
        }
        return order;
    }

private:
    bool recurse(int course, vector<vector<int>>& prs, vector<bool>& determined, vector<bool>& path, vector<int>& order){
        if(determined[course]) return true;

        path[course] = true;
        for(int precourse : prs[course]){
            if(path[precourse] == true || !recurse(precourse, prs, determined, path, order))
                return false;
        }
        determined[course] = true;
        path[course] = false;
        order.push_back(course);
        return true;
    }
};