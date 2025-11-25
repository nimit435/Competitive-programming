#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <limits>
#include <set>

using namespace std;
class Solution {
public:
    int solution(std::vector<int>& heights, int viewingGap) {
        // Core logic to be implemented here
        set<int> s;
        int n = heights.size();
        
        vector<int> dp(n, 1e18);
        for(int i=viewingGap; i<n; i++){
            s.insert(heights[i-viewingGap]);
            auto closest = s.lower_bound(heights[i]);
            if(closest == s.end()){
                closest = prev(closest);
                dp[i] = min(dp[i-1], heights[i]- (*closest));
            }
            else if(*closest==heights[i]){
                dp[i] = 0;
            }
            else{
                auto less_eq = prev(closest);
                int mn = min(*closest-heights[i], heights[i]-(*less_eq));
                dp[i] = min(dp[i-1], mn);
            }
        }
        return dp[n-1];
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    int viewingGap;

    // Assuming the first line of input contains the number of peaks (n)
    // and the viewing gap, separated by a space.
    // The second line contains n space-separated integers for the heights.
    std::cin >> n >> viewingGap;

    std::vector<int> heights(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> heights[i];
    }

    Solution sol;
    int result = sol.solution(heights, viewingGap);

    std::cout << result << std::endl;

    return 0;
}