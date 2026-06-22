class Solution {
public:
    int search(vector<int>& nums, int target) {
        int leftPtr = 0, rightPtr = nums.size() - 1;

        while (leftPtr < rightPtr) {
            int midPtr = (leftPtr + rightPtr) / 2;

            if (nums[midPtr] < nums[rightPtr]) {
                rightPtr = midPtr;
            } else {
                leftPtr = midPtr + 1;
            }
        }

        int pivotStart = leftPtr;

        int resultIndex = binarySearch(nums, target, 0, pivotStart - 1);

        return resultIndex != -1 ? resultIndex : binarySearch(nums, target, pivotStart, nums.size()-1);

    }

    int binarySearch(vector<int>& nums, int target, int start, int end) {
        while (start <= end) {
            int mid = (start + end) / 2;

            if (nums[mid] > target) {
                end = mid - 1;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                return mid;
            }
        }

        return -1;
    }
};
