class Solution {
public:
    bool isValid(string s) {
        stack<char> bucket;

        unordered_map<char, char> validPair = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for(char c : s) {
            if (!bucket.empty() && bucket.top() == validPair[c]) {
                bucket.pop();
            } else {
                bucket.push(c);
            }
        }

        return bucket.empty();
    }
};
