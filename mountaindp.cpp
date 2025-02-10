#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
const int mod=1000000007;
long long dp[101][10001];
bool dpc[101][10001];
long long solve(int w, int ribbon,  int W, int H){
    if(ribbon<0){
        return 0;
    }
    else if(w>W){
        return 1;
    }
    else if(dpc[w][ribbon]){
        return dp[w][ribbon];
    }
    else{
        long long scenes=0;
        for(int len=0; len<=H; len++){
            scenes= scenes+solve(w+1,ribbon-len,W,H);
        }
        dp[w][ribbon]=scenes%mod;
        return dp[w][ribbon];
    }
}
int main(){
    int N;
    cin>>N;
    int W;
    cin>>W;
    int H;
    cin>>H;
    long long ribbon_squares= min(H*W,N);
    long long planes= floor(ribbon_squares/W)+1;
    long long res= (solve(1,N,W,H )-planes)%mod;
    cout<<res;
    return 0;
}