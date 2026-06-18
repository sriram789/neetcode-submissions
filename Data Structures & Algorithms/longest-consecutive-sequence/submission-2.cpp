class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> hashTable;
        int maxConsecutiveSequenceLength = 0;

        vector<int> possibleStartOfSequence;

        for (int num : nums) {
            hashTable[num] = true;

            if (hashTable.find(num - 1) == hashTable.end()) {
                possibleStartOfSequence.push_back(num);
            }
        }

        for (int num : possibleStartOfSequence) {
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
