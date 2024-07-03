#include <bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/set-matrix-zeroes/submissions/543699863?envType=study-plan-v2&envId=top-100-liked
class Solution {
public:
    // 使用矩阵本身存储一些不可逆的信息
    void setZeroes(vector<vector<int>>& matrix) {
        bool isFirst0 = false;
        for(int n:matrix[0]){
            if(n == 0){isFirst0=true;break;}
        }

        for(int i=matrix.size()-1; i>0; i--){
            bool has0 = false;
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0; // 待会清算
                    has0 = true;
                }
            }
            if(has0){
                matrix[i] = vector<int>(matrix[i].size()); // 行置为零  
            }
        }
        // 列置为1
        for(int i=0;i<matrix[0].size();i++){
            if(matrix[0][i] == 0){
                for(int k=1;k<matrix.size();k++){
                    matrix[k][i] = 0;
                }
            }
        }
        // 特判第一行
        if(isFirst0){
            matrix[0] = vector<int>(matrix[0].size());
        }
    }
};
