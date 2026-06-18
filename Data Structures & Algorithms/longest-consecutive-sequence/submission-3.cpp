class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> hashTable;
        int maxConsecutiveSequenceLength = 0;

        for (int num : nums)
            hashTable[num] = true;

        for (int num : nums) {
            if (hashTable.find(num - 1) == hashTable.end()) {
                int currentConsecutiveSequenceLength = 1;
                int valueToLookFor = num + 1;
                
                while (hashTable.find(valueToLookFor) != hashTable.end()) {
                    ++currentConsecutiveSequenceLength;
                    ++valueToLookFor;
                }

                if (currentConsecutiveSequenceLength > maxConsecutiveSequenceLength) {
                    maxConsecutiveSequenceLength = currentConsecutiveSequenceLength;
                }
            }
        }

        return maxConsecutiveSequenceLength;
    }
};
