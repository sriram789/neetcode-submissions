class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<array<int, 26>, vector<string>> hashMap;

        for (string s : strs) {
            hashMap[getHashArray(s)].push_back(s);
        }

        vector<vector<string>> finalResult;

        for (auto &entry : hashMap) {
            finalResult.push_back(entry.second);
        }

        return finalResult;
    }

    array<int, 26> getHashArray(string str) {
        array<int, 26> hashArray{};

        for (char c : str) {
            hashArray[c - 'a']++;
        }

        return hashArray;
    }
};
