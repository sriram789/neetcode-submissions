class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;

        for (int index = 0 ; index < nums.size() ; index++) {
            // In sorted array next element will always be greater 
            // so if first itself is greater than 0,
            // we can't form a triplet which results in 0
            if (nums[index] > 0) break; 

            // We want to form triplets with unique values, 
            // so skipping entries which are same
            if (index > 0 && nums[index] == nums[index - 1]) continue;


            int leftPtr = index + 1, rightPtr = nums.size() - 1;

            while (leftPtr < rightPtr) {
                int sum = nums[index] + nums[leftPtr] + nums[rightPtr];

                if (sum < 0) {
                    ++leftPtr;
                } else if (sum > 0) {
                    --rightPtr;
                } else {
                    result.push_back({nums[index], nums[leftPtr], nums[rightPtr]});

                    ++leftPtr; --rightPtr;

                    // To skip all the similar entries
                    while (leftPtr < rightPtr && nums[leftPtr] == nums[leftPtr - 1])
                        leftPtr++;
                }
            }
        }

        return result;
    }
};
