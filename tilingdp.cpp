#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include<limits.h>
#include <string>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
// #include <bits/stdc++.h>

using namespace std;


//Main
int main() {
    while(true){
        long long n;
        cin >> n;
        if(n==-1){
            break;
        }
        int dp[n+1][8];
        
        for(int i=0; i<n+1; i++){
            for(int j=0; j<8; j++){
                dp[i][j]=0;
            }
        }
        dp[0][7]=1;
        
        for(int i= 1; i<n+1; i++){
            dp[i][0]=dp[i-1][7];
            dp[i][1]=dp[i-1][6];
            dp[i][3]=dp[i-1][7]+dp[i-1][4];
            dp[i][4]=dp[i-1][3];
            dp[i][6]=dp[i-1][7]+dp[i-1][1];
            dp[i][7]=dp[i-1][6]+dp[i-1][3]+dp[i-1][0];
        }
        cout<<dp[n][7]<<endl;
    }
    
  
    return 0;
}