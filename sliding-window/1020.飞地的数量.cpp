/*
 * @lc app=leetcode.cn id=1020 lang=cpp
 *
 * [1020] 飞地的数量
 */

 // @lc code=start
class Solution {
public:
    void color(vector < vector<int>>& c, int i, int j) {
        if (i >= c.size() || j >= c[0].size() || i < 0 || j < 0) {
            return;
        }
        if (c[i][j] != 1) {
            return;
        }
        c[i][j] = 2;
        color(c, i + 1, j);
        color(c, i - 1, j);
        color(c, i, j + 1);
        color(c, i, j - 1);
        return;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size();++i) {
            color(grid, i, 0);
            color(grid, i, grid[0].size() - 1);
        }
        for (int i = 0; i < grid[0].size();++i) {
            color(grid, 0, i);
            color(grid, grid.size() - 1, i);
        }

        int ans = 0;
        for (auto& it : grid) {
            for (auto& num : it) {
                if (num == 1) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

