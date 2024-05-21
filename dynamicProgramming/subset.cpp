class Solution {
public:

    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        std::vector<std::vector<int>> ret;
        std::vector<std::vector<int>> temp;
        std::vector<int> location(size, -1);
        for (int i = 0; i <= size; i++) {
            std::vector<std::vector<int>> temp2;
            if (i == 0) {
                std::vector<int> s;
                ret.push_back(s);
                temp2.push_back(s);
                temp.clear();
                temp = temp2;
                continue;
            }
            for (int index = 0; index < size; index++) {
                int t_size = temp.size();
                int loc = index == 0 ? 0 : location[index - 1];
                int remainder = i - 1;
                if (remainder > 0) {
                    for (int k = location[index]; k >= 0 && k < t_size && temp[k].size() == remainder; k++) {
                        if (temp[k].size() == (i - 1)) {
                            if (temp[k].size() > 0 &&  temp[k][0] != nums[index]) {
                                std::vector<int> new_set;
                                new_set.push_back(nums[index]);
                                new_set.insert(new_set.end(), temp[k].begin(), temp[k].end());
                                temp2.push_back(new_set);
                                ret.push_back(new_set);
                            }
                        }
                        loc += 1;
                    }
                } else {
                    loc += 1;
                    std::vector<int> new_set;
                    new_set.push_back(nums[index]);
                    ret.push_back(new_set);
                    temp2.push_back(new_set);
                }
                location[index] = loc;
            }
            temp.clear();
            temp = temp2;
        }
        return ret;
    }
};