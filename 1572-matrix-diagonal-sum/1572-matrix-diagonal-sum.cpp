class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;
        for(int i = 0; i<mat.size(); i++){
            for(int j = 0; j<mat[0].size(); j++){
                if(i==j){
                 sum += mat[i][j];

                 }else if(j== n-i-1){
                    sum += mat[i][j];
                }
            }
        }
        return sum;
    }
};