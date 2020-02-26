#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> ret;
        if(num == 0)
            return {"0:00"};
        vector<int> positions;
        for(int i = 0; i < num; i++)
            positions.push_back(i);
        while(true){
            string time = position2time(positions);
            if(!time.empty())
                ret.push_back(position2time(positions));
            while(!positions.empty() && positions.back() == 9 - num + positions.size())
                positions.pop_back();
            if(positions.empty())
                break;
            
            positions.back()++;
            while(positions.size() < num)
                positions.push_back(positions.back() + 1);
        }
        return ret;
    }

private:
    string position2time(const vector<int>& pos){
        ostringstream oss;
        int hour = 0, minute = 0;
        int i = 0;
        while(i < pos.size() && pos[i] < 4){
            hour += 1 << pos[i];
            i++;
        }
        while(i < pos.size()){
            minute += 1 << (pos[i] - 4);
            i++;
        }
        if(hour >= 12 || minute >= 60)
            return string();
        oss << hour << ":";
        if(minute < 10)
            oss << 0;
        oss << minute;
        return oss.str();
    }
};