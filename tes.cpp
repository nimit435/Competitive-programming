#include <bits/stdc++.h>
using namespace std;

/*
 * extend_diff_matrix marks a flip of all bits in the subrectangle 
 * (r1,c1) to (r2,c2) by XOR’ing the corners in the diff matrix.
 */
void extend_diff_matrix(vector<vector<int>>& diff, int r1, int c1, int r2, int c2) {
    diff[r1][c1] ^= 1;
    if (c2 + 1 < (int)diff[0].size()) 
        diff[r1][c2+1] ^= 1;
    if (r2 + 1 < (int)diff.size()) 
        diff[r2+1][c1] ^= 1;
    if (r2 + 1 < (int)diff.size() && c2 + 1 < (int)diff[0].size())
        diff[r2+1][c2+1] ^= 1;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];  // original boolean matrix (0 or 1)
        }
    }
    // diff is (n+1)x(m+1) to allow marking beyond edges
    vector<vector<int>> diff(n+1, vector<int>(m+1, 0));
    int moves = 0;
    
    // Scan through the matrix; compute current effective bit via prefix XOR of diff.
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int sum = 0;
            // Compute prefix XOR of diff up to (i,j)
            for(int x = 0; x <= i; x++){
                for(int y = 0; y <= j; y++){
                    sum ^= diff[x][y];
                }
            }
            // Effective bit at (i,j) = original XOR accumulated flips
            int cur = a[i][j] ^ sum;
            if(cur == 1) {
                // We need to flip this bit. Flip the rectangle (i,j) to (n-1,m-1).
                moves++;
                extend_diff_matrix(diff, i, j, n-1, m-1);
            }
        }
    }

    cout << moves << "\n";
    return 0;
}