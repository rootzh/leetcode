/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

 // @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int x = -1;
        int curTotal = 0;
        int ans = 100001;
        int size = nums.size();
        for (int i = 0; i < size;++i) {
            curTotal += nums[i];
            while (curTotal >= target) {
                ans = ans > i - x ? ans = i - x : ans;
                ++x;
                curTotal -= nums[x];
            }
        }
        return ans == 100001 ? 0 : ans;
    }
};
// @lc code=end

