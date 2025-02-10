#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>
#include <climits>
using namespace std;

long long dp[201][201][2];
bool dpc[201][201][2];
long long f(int k, int r, int c , int arr[][2]){
    if(k==0){
        return 0;
    }
    else if(r<0){
        return INT_MAX;
    }
    else if(dpc[k][r][c]){
        return dp[k][r][c];
    }
    else{
        if(c==0){
            long long a= min(arr[r][c]+f(k-1,r-1,0,arr),f(k,r-1,0,arr));
            dp[k][r][c]= min(a,f(k,r-1,1,arr));
            dpc[k][r][c]=true;
            cout<<k<<" "<<r<<" "<<c<<" "<<dp[k][r][c]<<endl;

            return dp[k][r][c];
        }
        else{
            long long a= min(arr[r][c]+f(k-1,r-1,1,arr),f(k,r-1,1,arr));
            dp[k][r][c]= min(a,f(k,r-1,0,arr));
            dpc[k][r][c]=true;
            cout<<k<<" "<<r<<" "<<c<<" "<<dp[k][r][c]<<endl;

            return dp[k][r][c];

        }
    }
}
long long solve(int arr[][2], int N, int K){
    long long sum=0;
    for(int i=0; i<N; i++ ){
        sum=sum+arr[i][0]+arr[i][1];
    }
    return sum- min(f(K,N-1, 0,arr ),f(K,N-1,1,arr));

}

int main(){
    int N;
    cin>>N;
    int K;
    cin>>K;
    int arr[N][2];
    for(int i=0; i<N; i++){
        cin>>arr[i][0];
        cin>>arr[i][1];
    }
    int fal1;
    int fal2;
    cin>>fal1>>fal2;
    long long res= solve(arr, N, K);
    cout<<res<<endl;
}