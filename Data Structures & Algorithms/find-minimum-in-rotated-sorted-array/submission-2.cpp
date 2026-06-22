class Solution {
public:
    int findMin(vector<int> &nums) {
        int leftPtr = 0, rightPtr = nums.size() - 1;

        while (leftPtr < rightPtr) {
            int midPtr = (leftPtr + rightPtr) / 2;

            if (nums[midPtr] < nums[rightPtr]) {
                rightPtr = midPtr;
            } else {
                leftPtr = midPtr + 1;
            }
        }

        return nums[leftPtr];
    }
};
