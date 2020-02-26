#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        if (board.empty() || board[0].empty() || word.empty())
            return false;

        rows = board.size();
        cols = board[0].size();

        vector<vector<bool>> used(rows, vector<bool>(cols, false));
        IndexType index, neighbour_index;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (board[i][j] == word[0])
                {
                    vector<IndexType> part_word;
                    index = make_pair(i, j);
                    neighbour_index = make_pair(i, j);
                    part_word.push_back(index);
                    used[i][j] = true;
                    if (word.size() == part_word.size())
                        return true;
                    while (true)
                    {
                        if (!next_neighbour(index, neighbour_index, used))
                        {
                            neighbour_index = part_word.back();
                            used[neighbour_index.first][neighbour_index.second] = false;
                            part_word.pop_back();
                            if (part_word.empty())
                                break;
                            index = part_word.back();
                        }
                        else
                        {
                            if (word[part_word.size()] == board[neighbour_index.first][neighbour_index.second])
                            {
                                part_word.push_back(neighbour_index);
                                index = neighbour_index;
                                used[index.first][index.second] = true;
                                if (part_word.size() == word.size())
                                    return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }

private:
    int rows, cols;
    using IndexType = pair<int, int>;

    bool next_neighbour(const IndexType &index, IndexType &neighbour_index, const vector<vector<bool>> &used)
    {
        static set<IndexType> displacements = {make_pair(0, 1),
                                               make_pair(-1, 0),
                                               make_pair(0, -1),
                                               make_pair(1, 0)};

        IndexType disp = make_pair(neighbour_index.first - index.first, neighbour_index.second - index.second);
        auto it = displacements.find(disp);
        if (it == displacements.end())
            it = displacements.begin();
        else
            it++;
        while (it != displacements.end())
        {
            neighbour_index = get_index(index, *it);
            if (is_vaild_index(neighbour_index, used))
                return true;
            it++;
        }
        return false;
    }

    IndexType get_index(const IndexType &index, const IndexType &displacement)
    {
        return make_pair(index.first + displacement.first, index.second + displacement.second);
    }

    bool is_vaild_index(const IndexType &index, const vector<vector<bool>> &used)
    {
        return index.first >= 0 && index.first < rows && index.second >= 0 && index.second < cols && (!used[index.first][index.second]);
    }
};