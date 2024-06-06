// https://leetcode.cn/problems/decode-string/?envType=study-plan-v2&envId=top-100-liked
// 394. 字符串解码
// 给定一个经过编码的字符串，返回它解码后的字符串。
// 编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
// 你可以认为输入字符串总是有效的；如果输入字符串含有不匹配的左/右括号，则需要去除最小数量的无效括号以保证输入字符串格式正确。
// 示例 1：
// 输入：s = "3[a]2[bc]"
// 输出："aaabcbc"
// 示例 2：
// 输入：s = "3[a2[c]]"
// 输出："accaccacc"
// 示例 3：
// 输入：s = "2[abc]3[cd]efxgh"
// 输出："abcabccdcdcdefgh"
// 示例 4：
// 输入：s = "abc3[cd]xyz"
// 输出："abccdcdcdxyz"

class Solution {
public:
    string decodeString(string s) {
        std::string ret = "";
        std::string digtals = "";
        int size = s.size();
        for (int i = 0; i < size;) {
            if (s[i] >= '0' && s[i] <= '9') {
                digtals += s[i];
                i += 1;
            } else if (s[i] == '[') {
                int left_bracket = 1;
                int right_bracket = 0;
                std::string sub_str = "";
                std::string sub_ret = "";
                i += 1;
                while(left_bracket != right_bracket) {
                    if (s[i] == '[') {
                        left_bracket += 1;
                    }
                    if (s[i] == ']') {
                        right_bracket += 1;
                        if (left_bracket == right_bracket) {
                            sub_ret = decodeString(sub_str);
                            i += 1;
                            break;
                        }
                    }
                    sub_str += s[i];
                    i += 1;
                }
                if (digtals.empty()) {
                    ret += sub_ret;
                } else {
                    int repeat_num = std::atoi(digtals.c_str());
                    for (int index = 0; index < repeat_num; index++) {
                        ret += sub_ret;
                    }
                }
                digtals = "";

            } else {
                ret += s[i];
                i += 1;
            }
        }
        return ret;
    }
};