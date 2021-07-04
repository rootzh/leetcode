/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

 // @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        set<char> inQueue;
        deque<int> q;
        int max = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (inQueue.find(s[i]) != inQueue.end()) {
                while (s[q.front()] != s[i]) {
                    inQueue.erase(s[q.front()]);
                    q.pop_front();
                }
                inQueue.erase(s[q.front()]);
                q.pop_front();
            }
            q.push_back(i);
            inQueue.insert(s[i]);
            max = max > q.size() ? max : q.size();
        }
        return max;
    }
};
// @lc code=end
