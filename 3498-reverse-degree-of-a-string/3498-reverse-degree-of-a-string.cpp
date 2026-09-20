class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;

        for (int i = 0; i < s.length(); i++) {
            int reverseAlphabet = 'z' - s[i] + 1;
            sum += reverseAlphabet * (i + 1);
        }

        return sum;
    }
};