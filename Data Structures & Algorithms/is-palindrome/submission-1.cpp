class Solution {
public:
    bool isPalindrome(string s) {
        bool result = true;
        for (int startPointer = 0, endPointer = s.size() - 1; startPointer <= endPointer; ++startPointer, --endPointer) {
            while (startPointer < endPointer && !isalnum(s[startPointer]))
                ++startPointer;

            while (startPointer < endPointer && !isalnum(s[endPointer]))
                --endPointer;

            if (tolower(s[startPointer]) != tolower(s[endPointer])) {
                result = false;
                break;
            }
        }

        return result;
    }
};
