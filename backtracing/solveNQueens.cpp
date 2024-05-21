// https://leetcode.cn/problems/n-queens/?envType=study-plan-v2&envId=top-100-liked

class Solution {
public:
    bool check(std::pair<int, int>& lhs, std::pair<int, int>& rhs) {
        // if (lhs.empty() || rhs.empty) return true;
        if (lhs.first == rhs.first || lhs.second == rhs.second) {
            return false;
        }
        if (lhs.first - rhs.first == lhs.second - rhs.second || lhs.first - rhs.first == rhs.second - lhs.second) {
            return false;
        }
        return true;
    }
    void backtracing(int n, int row, std::vector<std::pair<int, int>>& locs, std::vector<std::vector<std::pair<int, int>>>& ret) {
        if (locs.size() == n) {
            ret.push_back(locs);
            return;
        }
        for (int col = 0; col < n; col++) {
            auto loc = std::make_pair(row, col);
            bool good = true;
            for (int i = 0; i < locs.size(); i++) {
                if (!check(loc, locs[i])) {
                    good = false;
                    break;
                }
            }
            if (good) {
                locs.push_back(loc);
                backtracing(n, row + 1, locs, ret);
                locs.pop_back();
            }
            // locs.pop_back();
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        std::vector<std::pair<int, int>> locs;
        std::vector<std::vector<std::pair<int, int>>> ret;
        backtracing(n, 0, locs,  ret);
        std:vector<std::vector<string>> ret_vec;
        for (int index = 0; index < ret.size(); index++) {
            std::vector<std::string> str_vec;
            for (int p_index = 0; p_index < ret[index].size(); p_index++) {
                std::string str = "";
                for (int i = 0; i < n; i++) {
                    if (i == ret[index][p_index].second) {
                        str += "Q";
                    } else {
                        str += ".";
                    }
                }
                str_vec.push_back(str);
            }
            ret_vec.push_back(str_vec);
        }
        return ret_vec;
    }
};