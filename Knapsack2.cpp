#include <iostream>
#include <cmath>
#include <vector>
#include <climits>

using namespace std;

long long dp[110][100010];

long long func(int ind, int val, int arr[][2]){
  if(val==0){
    return 0;
  }
  if(ind<0){
    return 1e15;
  }
  if(dp[ind][val]!=-1){
    return dp[ind][val];
  }
  else{
    if(val-arr[ind][1]>=0)
    dp[ind][val]= min(arr[ind][0]+ func(ind-1, val-arr[ind][1], arr), func(ind-1,val,arr));
    return dp[ind][val];
  }
}
int main(){
    memset(dp, -1, sizeof(dp));
    for(int )
}