/*
 * @lc app=leetcode.cn id=1208 lang=cpp
 *
 * [1208] 尽可能使字符串相等
 */

 // @lc code=start
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        deque<int> q;
        int curTotalCost = 0;
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            curTotalCost += abs(s[i] - t[i]);
            q.push_back(i);
            while (curTotalCost > maxCost && !q.empty()) {
                curTotalCost -= abs(s[q.front()] - t[q.front()]);
                q.pop_front();
            }
            if (ans < q.size()) {
                ans = q.size();
            }
        }
        return ans;
    }
};
// @lc code=end

