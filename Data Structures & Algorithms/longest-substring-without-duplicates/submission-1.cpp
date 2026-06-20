class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> uniqueChar;

        int maxLength = 0;
        int leftPtr = 0, rightPtr = 0;

        while (rightPtr < s.size()) {
            if(uniqueChar.find(s[rightPtr]) == uniqueChar.end()) {
                uniqueChar.insert(s[rightPtr]);
                ++rightPtr;
                maxLength = max(maxLength, static_cast<int>(uniqueChar.size()));
            } else {
                uniqueChar.erase(s[leftPtr]);
                ++leftPtr;
            }
        }

        return maxLength;
    }
};
