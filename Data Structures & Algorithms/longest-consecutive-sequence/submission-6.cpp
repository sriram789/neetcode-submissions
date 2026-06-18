class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashTable;
        int maxConsecutiveSequenceLength = 0;

        for (int num : nums) {
            hashTable.insert(num);
        }

        for (int num : nums) {
            if (hashTable.find(num - 1) == hashTable.end()) {
                int currentConsecutiveSequenceLength = 1;
                int valueToLookFor = num + 1;
                
                while (hashTable.find(valueToLookFor) != hashTable.end()) {
                    ++currentConsecutiveSequenceLength;
                    ++valueToLookFor;
                }

                maxConsecutiveSequenceLength = max(maxConsecutiveSequenceLength, currentConsecutiveSequenceLength);
            }
        }

        return maxConsecutiveSequenceLength;
    }
};
