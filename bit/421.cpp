#include <vector>
using namespace std;

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int max = 0;
        for (int i = 0; i<nums.size()-1;++i) {
            for (int j = i+1; j <nums.size();j++){
                if (max < (nums[i] ^ nums[j])) {
                    max = nums[i] ^ nums[j];
                }
            }
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        return max;
    }
};

int main() {
    Solution s;
    vector<int> nums{3,10,5,25,2,8};
    s.findMaximumXOR(nums);
}
