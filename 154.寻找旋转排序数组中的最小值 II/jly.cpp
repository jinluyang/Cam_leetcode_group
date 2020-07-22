class Solution {
public:
    int findMinSub(vector<int>& nums, int beg, int end) {
        if (beg == end)
            return nums[beg];
        if (beg + 1 == end)
            return nums[beg] < nums[end] ? nums[beg] : nums[end];
        if (nums[beg] < nums[end])
            return nums[beg];
        int mid = (beg + end) / 2;
        if (nums[mid] > nums[beg])
            return findMinSub(nums, mid, end);
        else if (nums[mid] < nums[beg])
            return findMinSub(nums, beg, mid);
        else {
            //if (nums[beg] > nums[end])
            return findMinSub(nums, mid, end);
        }

    }
    int findMin(vector<int>& nums) {
        //int lenth = nums.size();
        
        int end = nums.size()-1;
        while (nums[0] == nums[end] && end != 0)
            end--;
        if (end == 0)
            return nums[0];
        if (nums[0] < nums[end])
            return nums[0];
        return findMinSub(nums, 0, end);
    }
};
