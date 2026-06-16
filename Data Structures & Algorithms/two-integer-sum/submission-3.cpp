class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> lookupTable;
        lookupTable.reserve(nums.size());

        for (int index = 0 ; index < nums.size() ; index++) {
            int difference = target - nums[index];

            if (lookupTable.find(difference) != lookupTable.end()) {
                return vector<int>{lookupTable[difference], index};
            }

            lookupTable[nums[index]] = index;
        }

        return {};
    }
};
