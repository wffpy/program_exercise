// https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/description/?envType=study-plan-v2&envId=top-100-liked
//
class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();
        if (nums[0] < nums[size - 1]) {
            return nums[0];
        }
        int left = 0;
        int right = size - 1;
        while (left < right) {
            int new_index = (left + right) / 2;
            if (left == new_index){
                break;
            }
            if (nums[new_index] > nums[right]) {
                left = new_index;
            } else {
                right = new_index;
            }
        }
        return nums[right];
    }
};
