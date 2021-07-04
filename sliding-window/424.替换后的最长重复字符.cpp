/*
 * @lc app=leetcode.cn id=424 lang=cpp
 *
 * [424] 替换后的最长重复字符
 */

 // @lc code=start
class Solution {
public:

    int getCharacterReplacement(string s, int k) {
        deque<int> subStr;
        int max = 0;
        int maxNum = 0;
        map<char, int> num;
        for (int i = 0; i < s.size(); ++i) {
            if (!subStr.empty()) {
                int tmp = num[s[i]] + 1;
                maxNum = maxNum > tmp ? maxNum : tmp;
                if (k < subStr.size() + 1 - maxNum) {
                    --num[s[subStr.front()]];
                    subStr.pop_front();
                }
            }
            subStr.push_back(i);
            num[s[i]]++;
            max = max > subStr.size() ? max : subStr.size();
        }

        return max;
    }

    int characterReplacement(string s, int k) {
        int max = getCharacterReplacement(s, k);
        return max;
    }
};
// @lc code=end

