class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> last_idx;
        int least_dist = nums.size() + 1;
        for (int i = 0; i < nums.size(); i++) {
            if (last_idx.find(nums[i]) == last_idx.end()) {
                last_idx[nums[i]] = i;
            } else {
                if (i - last_idx[nums[i]] <= k)
                    return true;
                else
                    last_idx[nums[i]] = i;
            }
        }
        return false;
    }
};
