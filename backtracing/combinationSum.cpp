// https://leetcode.cn/problems/combination-sum/?envType=study-plan-v2&envId=top-100-liked

class Solution {
public:
    void backtracing(std::vector<int>& candidates, int target, std::vector<int>& vec, std::vector<std::vector<int>>& ret, int start) {
        int sum = std::accumulate(vec.begin(), vec.end(), 0);
        if (sum == target) {
            ret.push_back(vec);
            return;
        } else if (sum > target) {
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            vec.push_back(candidates[i]);
            backtracing(candidates, target, vec, ret, i);
            vec.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::vector<std::vector<int>> ret;
        std::vector<int> vec;
        backtracing(candidates, target, vec, ret, 0);
        return ret;
    }
};