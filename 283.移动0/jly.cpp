class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() <= 1)
            return;
        int head = 0;
        int p = 0;
        while (p <= nums.size()-1) {
            if (nums[p] != 0) {
                nums[head] = nums[p];
                p++;
                head++;
            } else {
                p++;
            }
        }
        while (head <= nums.size()-1) {
            nums[head] = 0;
            head++;
        }
    }
};
