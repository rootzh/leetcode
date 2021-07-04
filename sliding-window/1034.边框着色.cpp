/*
 * @lc app=leetcode.cn id=1034 lang=cpp
 *
 * [1034] 边框着色
 */

 // @lc code=start
class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<pair<int, int>>& flags, int i, int j, const int& sourceColor) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
            return;
        }
        if (grid[i][j] != sourceColor || done.find(i * 100 + j) != done.end()) {
            return;
        }
        done.insert(i * 100 + j);
        if (i == 0 || i == grid.size() - 1 || j == 0 || j == grid[0].size() - 1) {
            flags.push_back(make_pair(i, j));
        }
        else if ((grid[i - 1][j] != sourceColor || grid[i + 1][j] != sourceColor ||
            grid[i][j + 1] != sourceColor || grid[i][j - 1] != sourceColor)) {
            flags.push_back(make_pair(i, j));
        }
        dfs(grid, flags, i + 1, j, sourceColor);
        dfs(grid, flags, i - 1, j, sourceColor);
        dfs(grid, flags, i, j + 1, sourceColor);
        dfs(grid, flags, i, j - 1, sourceColor);
        return;
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        vector<pair<int, int>> flags;
        dfs(grid, flags, r0, c0, grid[r0][c0]);
        for (auto& it : flags) {
            grid[it.first][it.second] = color;
        }
        return grid;
    }
private:
    set<int> done;
};
// @lc code=end

