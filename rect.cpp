#include "solution.h"
#include <vector>
using namespace std;
namespace solution{
    void extend_diff_matrix(int i, int j, vector<vector<bool>>& matrix){
        for(int k=0; k<=i; k++){
            for(int l=0; l<=j; l++){
                matrix[k][l] = !matrix[k][l];
            }
        }
    }
    int solve(int m, int n, vector<vector<bool>> matrix) { 
        int t_cnt = 0;
        int f_cnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]){
                    t_cnt++;
                }
                else{
                    f_cnt++;
                }
            }
        }
        if(t_cnt == 0){
            return 0;
        }
        else if(f_cnt == 0){
            return 1;
        }
        else if(t_cnt == 1){
            return 1;
        }
        else if(f_cnt == 1){
            return 2;
        }
        else{
            int flip = 0;
            for(int i= m-1; i>=0; i--){
                for(int j = n-1; j>=0; j--){
                    if(matrix[i][j]){
                        flip++;
                        extend_diff_matrix(i,j,matrix);
                        
                    }
                }
            }
            return flip;
        }
    }
}