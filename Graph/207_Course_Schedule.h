#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<bool>> prs(numCourses, vector<bool>(numCourses, false));
        vector<int> prscount(numCourses, 0);
        for(auto v : prerequisites){
            prs[v[0]][v[1]] = true;
            prscount[v[0]]++;
        }
        vector<bool> visited(numCourses, false);
        int count = 0;
        while(true){
            int course = 0;
            while(course < numCourses){
                if(visited[course] == false && prscount[course] == 0) break;
                course++;
            }
            if(course == numCourses) break;
            visited[course] = true;
            count++;
            for(int i = 0; i < numCourses; i++){
                if(prs[i][course]){
                    prs[i][course] = false;
                    prscount[i]--;
                }
            }
        }
        return count == numCourses;
    }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> prs(numCourses);
        for(auto& v : prerequisites)
            prs[v[0]].push_back(v[1]);
        
        vector<bool> determined(numCourses, false);
        vector<bool> path(numCourses, false);
        for(int course = 0; course < numCourses; course++){
            if(!recurse(course, prs, determined, path))
                return false;
        }
        return true;
    }

private:
    bool recurse(int course, vector<vector<int>>& prs, vector<bool>& determined, vector<bool>& path){
        if(determined[course]) return true;

        path[course] = true;
        for(int precourse : prs[course]){
            if(path[precourse] == true || !recurse(precourse, prs, determined, path))
                return false;
        }
        determined[course] = true;
        path[course] = false;
        return true;
    }
};