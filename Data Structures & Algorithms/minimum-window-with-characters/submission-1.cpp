class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size() || t.empty()) return "";

        unordered_map<char, int> baseCount;
        for (char a : t) baseCount[a]++;

        int leftPtr = 0, rightPtr = 0;
        string result = "";
        int have = 0, need = baseCount.size();

        unordered_map<char, int> currentCount;

        while (rightPtr < s.size()) {
            char c = s[rightPtr];
            currentCount[c]++;

            if (baseCount.count(c) && currentCount[c] == baseCount[c]) {
                have++;
            }

            while (have == need) {
                if (result.empty() || result.size() > rightPtr - leftPtr + 1) {
                    result = s.substr(leftPtr, rightPtr - leftPtr + 1);
                }

                char leftMostChar = s[leftPtr];
                currentCount[leftMostChar]--;
                if (baseCount.count(leftMostChar) && currentCount[leftMostChar] < baseCount[leftMostChar]) {
                    have--;
                }
                leftPtr++;
            }

            rightPtr++;
        }

        return result;
    }
};
