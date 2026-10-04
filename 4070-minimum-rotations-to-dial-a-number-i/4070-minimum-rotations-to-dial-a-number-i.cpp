class Solution {
public:
    int minRotations(string s) {
        int ans = 0;
        int current = 0;

        for(char c : s){
            int target = c - '0';

            int diff = abs(target - current);

            ans += min(diff, 10 - diff);

             current = target;
        }
        return ans;
    }
};