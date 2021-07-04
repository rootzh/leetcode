class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int max = -30000;
        int tmp = 0;
        for (auto& num : nums) {
            tmp += num;
            max = max > tmp ? max : tmp;
            tmp = tmp < 0 ? 0 : tmp;
        }
        vector<int> sumRight(nums.size());
        sumRight[nums.size() - 1] = nums[nums.size() - 1];
        for (int i= nums.size() - 2; i>=0; --i) {
            sumRight[i] = sumRight[i+1] + nums[i];
        }
        vector<int> maxRight(nums.size());
        maxRight[nums.size()-1] = nums[nums.size() -1];
        for (int i= nums.size() -2; i>=0; --i) {
            maxRight[i] = maxRight[i+1] > sumRight[i] ? maxRight[i+1] : sumRight[i];
        }

        int left =0;
        for (int i = 0; i<nums.size(); ++i) {
            max = max > left + maxRight[i] ? max : left + maxRight[i];
            left = left + nums[i];
        }

        return max;
    }
};