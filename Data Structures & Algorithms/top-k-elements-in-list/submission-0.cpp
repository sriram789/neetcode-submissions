class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequencyCounter;
        vector<vector<int>> bucket(nums.size() + 1);

        for (int num : nums) {
            frequencyCounter[num] += 1;
        }

        for (const auto& entry : frequencyCounter) {
            bucket[entry.second].push_back(entry.first);
        }

        vector<int> result;
        for (int index = bucket.size() - 1 ; index > 0; --index) {
            for (int values : bucket[index]) {
                result.push_back(values);

                if (result.size() == k) {
                    return result;
                }
            }
        }

        return result;
    }
};
