class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> frequencyTrackerA;
        for (int index = 0; index < s.size(); index++) {
            if (frequencyTrackerA.find(s[index]) != frequencyTrackerA.end()) {
                frequencyTrackerA[s[index]] += frequencyTrackerA[s[index]];
            } else {
                frequencyTrackerA[s[index]] = 1;
            }
        }

        map<char, int> frequencyTrackerB;
        for (int index = 0; index < t.size(); index++) {
            if (frequencyTrackerB.find(t[index]) != frequencyTrackerB.end()) {
                frequencyTrackerB[t[index]] += frequencyTrackerB[t[index]];
            } else {
                frequencyTrackerB[t[index]] = 1;
            }
        }

        if (frequencyTrackerA.size() < frequencyTrackerB.size()) {
            for (const auto& [key, value] : frequencyTrackerB) {
                if (frequencyTrackerB[key] != frequencyTrackerA[key]) {
                    return false;
                }
            }
        } else {
            for (const auto& [key, value] : frequencyTrackerA) {
                if (frequencyTrackerA[key] != frequencyTrackerB[key]) {
                    return false;
                }
            }
        }

        return true;
    }
};
