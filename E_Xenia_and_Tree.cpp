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

// Macros
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define fl(i, n) for(int i = 0; i < n; i++)
#define rl(i, m, n) for(int i = n; i >= m; i--)
#define frl(i,j,n) for(int i=j; i<n; i++)
#define py cout << "YES\n";
#define pm cout << "-1\n";
#define pn cout << "NO\n";
#define vr(v) v.begin(), v.end()
#define rv(v) v.end(), v.begin()
#define rev(v) v.rbegin(), v.rend()

//Debug
#ifdef TA77
#define debug(x) cerr << #x << " "; cerr << x << " "; cerr << endl;
#else
#define debug(x);
#endif

// Operator overloads
template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}
template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }

// Utility functions
template <typename T>
void print(T &&t) { cout << t << "\n"; }
void printarr(ll arr[], ll n) { fl(i, n) cout << arr[i] << " "; cout << "\n"; }
template<typename T>
void printvec(vector<T> v) { ll n = v.size(); fl(i, n) cout << v[i] << " "; cout << "\n"; }
template<typename T>
ll sumvec(vector<T> v) { ll n = v.size(); ll s = 0; fl(i, n) s += v[i]; return s; }

// Mathematical functions
ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b); } //__gcd
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }
ll moduloMultiplication(ll a, ll b, ll mod) { ll res = 0; a %= mod; while (b) { if (b & 1) res = (res + a) % mod; b >>= 1; } return res; }
ll powermod(ll x, ll y, ll p) { ll res = 1; x = x % p; if (x == 0) return 0; while (y > 0) { if (y & 1) res = (res * x) % p; y = y >> 1; x = (x * x) % p; } return res; }

//Sorting
bool sorta(const pair<int, int> &a, const pair<int, int> &b) { return (a.second < b.second); }
bool sortd(const pair<int, int> &a, const pair<int, int> &b) { return (a.second > b.second); }

//Bits
string decToBinary(int n) { string s = ""; int i = 0; while (n > 0) { s = to_string(n % 2) + s; n = n / 2; i++; } return s; }
ll binaryToDecimal(string n) { string num = n; ll dec_value = 0; int base = 1; int len = num.length(); for (int i = len - 1; i >= 0; i--) { if (num[i] == '1') dec_value += base; base = base * 2; } return dec_value; }

//Check
bool isPrime(ll n) { if (n <= 1) return false; if (n <= 3) return true; if (n % 2 == 0 || n % 33 == 0) return false; for (int i = 5; i * i <= n; i = i + 6) if (n % i == 0 || n % (i + 2) == 0) return false; return true; }
bool isPowerOfTwo(int n) { if (n == 0) return false; return (ceil(log2(n)) == floor(log2(n))); }
bool isPerfectSquare(ll x) { if (x >= 0) { ll sr = sqrt(x); return (sr * sr == x); } return false; }

//Number of Inversions
ll merge(vector<ll> &arr, ll low, ll mid, ll high) {vector<int> temp;ll left = low;ll right = mid + 1;ll cnt = 0;while (left <= mid && right <= high) {if (arr[left] <= arr[right]) {temp.push_back(arr[left]);left++;}else {temp.push_back(arr[right]);cnt += (mid - left + 1);right++;}}while (left <= mid) {temp.push_back(arr[left]);left++;}while (right <= high) {temp.push_back(arr[right]);right++;}for (int i = low; i <= high; i++) {arr[i] = temp[i - low];}return cnt;}
ll mergeSort(vector<ll> &arr, ll low, ll high) {int cnt = 0;if (low >= high) return cnt;int mid = (low + high) / 2;cnt += mergeSort(arr, low, mid);cnt += mergeSort(arr, mid + 1, high);cnt += merge(arr, low, mid, high);return cnt;}
ll numberOfInversions(vector<ll>&a, ll n) {return mergeSort(a, 0, n - 1);}

//Code
ll dfs(ll i, ll par, vll& chil, vvll& tree, vector<bool>& vis){
    if(vis[i]){
        return 0;
    }
    chil[i] = 1;
    for(auto it: tree[i]){
        if(it== par){
            continue;
        }

        chil[i] += dfs(it, i, chil, tree, vis);
    }
    return chil[i];
}
void dfsb(ll i, ll par,  vvll& tree, vll& depth, vll& parentb){

    for(auto it: tree[i]){

        if(it== par){
            continue;
        }
        parentb[it] = i;
        depth[it] = depth[i]+1;
        dfsb(it, i,  tree, depth, parentb);
    }

}

ll  find_centroid(ll i, ll par, vll& chil, vector<bool>& vis, vvll& tree, ll n ){
    for(auto it: tree[i]){
        if(it == par){
            continue;
        }
        if(!vis[it] && chil[it]*2>n){
            return find_centroid(it, i, chil,vis, tree, n);
        }
    }
    return i;
}

ll jump(ll u, ll dis, vvll& dp){
    for(int j=0; j<=31; j++){
        if((dis&(1LL<<j))!=0){
            u = dp[u][j];
        }
    }
    return u;
}
ll dist(ll u, ll v, vvll& dp, vvll& tree, vll& depth){

    if(u==v){
        return 0;
    }
 
    ll ou = u;
    ll ov = v;
    if(depth[u]>depth[v]){
        swap(u,v);
    }
    ll diff = depth[v]-depth[u];
    v = jump(v, diff, dp);
    ll c;
    if(u==v){
        c = u;
    }
    else{
        for(int j = 31; j>=0; j--){
            if(dp[u][j]!= dp[v][j]){
                u = dp[u][j];
                v = dp[v][j];
            }
        }
        c = dp[u][0];
    }
    
    return depth[ou]+depth[ov] - (2*depth[c]);
}
void init_centroid(ll i, ll par, vll& chil, vector<bool>& vis, vvll& tree, vll& parent){
    dfs(i, -1, chil, tree, vis);
    ll c = find_centroid(i, -1, chil, vis, tree, chil[i]);
    vis[c] = true; 
    parent[c] = par;
    for(auto it: tree[c]){
        if(!vis[it]){
            init_centroid(it, c, chil , vis, tree, parent);
        }
    }
}

void solve() {
    ll n;
    cin>>n;
    ll q;
    cin>>q;
    vvll tree(n);
    fl(i,n-1){
        ll u, v;
        cin>>u>>v;
        u--; v--;
        tree[u].pb(v);
        tree[v].pb(u);
    }
    vll depth(n,0);
    vector<bool> vis(n, false);
    vll chil(n, 0);
    vll parent(n);
    init_centroid(0, -1, chil , vis, tree, parent);
    // printvec(parent);
    vll parentb(n, 0);

    dfsb(0, -1, tree, depth , parentb);
    vll best(n , 1e16);
    vvll dp(n, vll(32));
    fl(i,n){
        dp[i][0] = parentb[i];
    }
    // printvec(parentb);

    for(int j =1; j<=31; j++){
        fl(i,n){
            dp[i][j] = dp[dp[i][j-1]][j-1];
        }
    }
    auto update = [&](ll v){
        best[v] = 0;
        ll u = v;
        while(parent[u]!=-1){
            u = parent[u];
            best[u] = min(best[u], dist(u, v, dp, tree, depth));
        }
    };
    auto query = [&](ll v){
        ll res = best[v];
        ll u = v;
        while(parent[u]!=-1){
            u = parent[u];
            res = min(res, best[u] + dist(u, v, dp , tree, depth));
        }
        return res;
    };
    update(0);
    // printvec(best);
    while(q--){
        ll op, v;
        cin>>op>>v;
        v--;
        if(op==1){
            update(v);
        }
        else{
            cout<<query(v)<<endl;
        }
    }
    
}
// Allah hu Akbar
// 1110011 1110100 1100001 1101100 1101011 1100101 1110010 100000 1110100 1100101 1110010 1101001 100000 1101101 1100001 1100001 100000 1101011 1101001
int main() {
    Code By Solve
    solve();
    return 0;
}