/*
 * @lc app=leetcode.cn id=1004 lang=cpp
 *
 * [1004] 最大连续1的个数 III
 */

 // @lc code=start
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int x = -1;
        int ans = 0;
        int curK = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                curK++;
            }
            while (curK > k && x < i) {
                ++x;
                if (nums[x] == 0) {
                    curK--;
                }
            }
            ans = ans < i - x ? i - x : ans;
        }
        return ans;
    }
};
// @lc code=end

