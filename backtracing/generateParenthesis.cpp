// https://leetcode.cn/problems/generate-parentheses/?envType=study-plan-v2&envId=top-100-liked
class Solution {
public:
    void backtracing(int left, int right, int n, std::string& str, std::vector<std::string>& ret) {
        if (left == n && right == n) {
            ret.push_back(str);
            return;
        }
        if (left == right) {
            str += "(";
            backtracing(left + 1, right, n, str, ret);
            str.pop_back();
        }
        if (left == n) {
            str += ")";
            backtracing(left, right + 1, n, str, ret);
            str.pop_back();
        }
        if (left > right && left < n) {
            str += "(";
            backtracing(left + 1, right, n, str, ret);
            str.pop_back();
            str += ")";
            backtracing(left, right + 1, n, str, ret);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        std::string str = "";
        std::vector<std::string> ret;
        backtracing(0, 0, n, str, ret);
        return ret;
    }
};