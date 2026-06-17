class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string;
        for (string str : strs) {
            encoded_string += to_string(str.size()) + '@' + str;
        }

        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_vector;
        
        int pointer_i = 0;
        while (pointer_i < s.size()) {
            int pointer_j = pointer_i;

            while (s[pointer_j] != '@') {
                ++pointer_j;
            }

            int length_of_one_string = stoi(s.substr(pointer_i, pointer_j - pointer_i));

            decoded_vector.push_back(s.substr(pointer_j + 1, length_of_one_string));

            pointer_i = pointer_j + length_of_one_string + 1;
        }

        return decoded_vector;
    }
};
