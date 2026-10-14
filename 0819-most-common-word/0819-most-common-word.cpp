
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban(banned.begin(), banned.end());
        unordered_map<string, int> freq;

        string word = "";
        string ans = "";
        int maxFreq = 0;

        for (int i = 0; i <= paragraph.size(); i++) {
            char c = (i < paragraph.size())
                         ? tolower(paragraph[i])
                         : ' ';

            if (isalpha(c)) {
                word += c;
            } else {
                if (!word.empty()) {
                    if (!ban.count(word)) {
                        freq[word]++;

                        if (freq[word] > maxFreq) {
                            maxFreq = freq[word];
                            ans = word;
                        }
                    }

                    word = "";
                }
            }
        }

        return ans;
    }
};
