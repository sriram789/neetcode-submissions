class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        
        vector<int> prefix(size);
        vector<int> suffix(size);
        vector<int> result(size);

        prefix[0] = 1;
        suffix[size-1] = 1;

        for (int index = 1; index < size ; index++) {
            prefix[index] = prefix[index - 1] * nums[index - 1];
        }

        for (int index = size-2; index >= 0; index--) {
            suffix[index] = suffix[index + 1] * nums[index + 1];
        }

        for (int index = 0; index < size ; index++) {
            result[index] = prefix[index] * suffix[index];
        }

        return result;
    }
};
