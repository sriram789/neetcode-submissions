class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> uniqueChar;

        int maxLength = 0;
        int leftPtr = 0, rightPtr = 0;

        while (rightPtr < s.size()) {
            if(uniqueChar.insert(s[rightPtr]).second) {
                rightPtr++;
                maxLength = max(maxLength, static_cast<int>(uniqueChar.size()));
            } else {
                uniqueChar.erase(s[leftPtr++]);
            }
        }

        return maxLength;
    }
};
