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

        map<char, int> freqencyTrackerWithMoreCharacters = frequencyTrackerA;
        map<char, int> freqencyTrackerWithLessCharacters = frequencyTrackerB;


        if (frequencyTrackerA.size() < frequencyTrackerB.size()) {
            freqencyTrackerWithMoreCharacters = frequencyTrackerB;
            freqencyTrackerWithLessCharacters = frequencyTrackerA;
        }

        for (const auto& [key, value] : freqencyTrackerWithMoreCharacters) {
            if (freqencyTrackerWithMoreCharacters[key] != freqencyTrackerWithLessCharacters[key]) {
                return false;
            }
        }

        return true;
    }
};
