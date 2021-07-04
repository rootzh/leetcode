/*
 * @lc app=leetcode.cn id=1037 lang=cpp
 *
 * [1037] 有效的回旋镖
 */

 // @lc code=start
class Solution {
public:
    bool check(int& x1, int& y1, int& x2, int& y2, int& x3, int& y3) {
        if ((x1 == x2 && y1 == y2) ||
            (x1 == x3 && y1 == y3) ||
            (x2 == x3 && y2 == y3)) {
            return false;
        }
        return (x2 - x1) * (y3 - y1) != (x3 - x1) * (y2 - y1);
    }
    bool isBoomerang(vector<vector<int>>& points) {
        if (points.size() != 3) {
            return false;
        }
        //return f(points[1][0], points[1][1], points[0][0], points[0][1]) != f(points[2][0], points[2][1], points[0][0], points[0][1]);
        return check(points[0][0], points[0][1], points[1][0], points[1][1], points[2][0], points[2][1]);
    }
};
// @lc code=end

