class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int, int> count;

        int leftPtr = 0, rightPtr = 0;
        int maxFreq = 0;
        int result = 0;

        while (rightPtr < s.size()) {
            count[s[rightPtr]]++;
            maxFreq = max(maxFreq, count[s[rightPtr]]);

            while (((rightPtr - leftPtr + 1) - maxFreq) > k)
                count[s[leftPtr++]]--;

            result = max(result, rightPtr - leftPtr + 1);
            rightPtr++;
        }

        return result;
    }
};
