/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

 // @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char, int> hasNum, num;
        for (auto& c : s1) {
            hasNum[c]++;
        }
        deque<char> q;
        for (int i = 0; i < s2.size(); ++i) {
            q.push_back(s2[i]);
            num[s2[i]]++;
            while (num[s2[i]] > hasNum[s2[i]]) {
                num[q.front()]--;
                q.pop_front();
            }
            if (hasNum[s2[i]] == 0) {
                q.clear();
                num.clear();
            }
            if (q.size() == s1.size()) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

