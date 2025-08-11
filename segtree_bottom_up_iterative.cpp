#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <string>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

//Speed
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Solve cout.tie(NULL);
#define endel '\n';

//Aliases
using ll = long long;
using lld = long double;
using ull = unsigned long long;

//Constants
const lld pi = 3.141592653589793238;
const ll INF = INT_MAX;
const ll mod = 1e9 + 7;

//TypeDEf
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
typedef vector<vector<pll> > vvpll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef unordered_map<ll, ll> umll;
typedef map<ll, ll> mll;
template<typename T>
void printvec(vector<T> v) { ll n = v.size(); fl(i, n) cout << v[i] << " "; cout << "\n"; }

using namespace std;
class Segtree{
    private: 
        long long size;
        vector<long long> tree;
    public:
        Segtree(vll& vec){
            size = vec.size();
            ll n = vec.size();
            tree.resize(2*n);
            copy(vec.begin(), vec.end(), tree.begin() +n);
            for(int v = n-1; v>=1; v--){
                tree[v] = max(tree[2*v], tree[2*v+1]);
            }
        }
        ll getmax(ll l,ll r){
            l += size;
            r += size;
            ll ans = 0;
            while(l<=r){
                if(l%2==1){
                    ans = max(ans, tree[l]);
                    l++;
                }
                if(r%2==0){
                    ans = max(ans, tree[r]);
                    r--;
                }
                l /= 2;
                r /= 2;
            }
            return ans;

        }
        void update(int i, int newval){
            i+=size;
            tree[i] = newval;
            while(i>1){
                i /= 2;
                tree[i] = min(tree[2*i], tree[2*i+1]);
            }
        }
        void display(){
            printvec(tree);
        }
 
};