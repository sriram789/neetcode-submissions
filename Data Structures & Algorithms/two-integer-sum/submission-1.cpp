class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> lookupTable;

        for (int index = 0 ; index < nums.size() ; index++) {
            int difference = target - nums[index];

            if (lookupTable.find(difference) != lookupTable.end()) {
                return vector<int>{lookupTable[difference], index};
            } else {
                lookupTable[nums[index]] = index;
            }
        }
    }
};
