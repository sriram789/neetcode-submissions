class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int> uniqueElements;
        for (int index=0; index < nums.size(); index++) {
            if (uniqueElements.contains(nums[index])) {
                return true;
            } else {
                uniqueElements.insert(nums[index]);
                continue;
            }
        }

        return false;
    }
};