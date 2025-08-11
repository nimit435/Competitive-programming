#include <iostream>
#include <vector>

using namespace std;

const int N = 2e5 + 5;
const int D = 30;
int parent[N][D];
//Code
int jump(int a, int k){
    for(int i=0; i<30; i++){
        if(k&(1<<i)){
            a = parent[a][i];
        }
    }
    return a;
}
void solve() {
    int n;
    cin>>n;
    int q;
    cin>>q;

    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        a--;
        parent[i][0] = a;
    }
    for(int d = 1; d<30; d++){
        for(int i=0; i<n; i++){
            parent[i][d] = parent[parent[i][d-1]][d-1];
        }
    }


    for(int i=0; i<q; i++){
        int u, k;

        cin>>u>>k;
        u--;
        cout<<jump(u,k)+1<<endl;
    }
    
}
// Allah hu Akbar
// 1110011 1110100 1100001 1101100 1101011 1100101 1110010 100000 1110100 1100101 1110010 1101001 100000 1101101 1100001 1100001 100000 1101011 1101001
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}