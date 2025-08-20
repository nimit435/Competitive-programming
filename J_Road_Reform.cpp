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
void dfs(ll i, vvll& graph, vector<bool>& vis, vvll& chil, vll& par, vll& depth){
    vis[i] = true;
    for(auto it: graph[i]){
        if(!vis[it]){
            par[it] = i;
            chil[i].pb(it);
            depth[it] = depth[i] +1;
            dfs(it, graph, vis, chil, par, depth);
        }
    }
}
void mark_hp(ll i, vvll& chil, vvll& graph, vll& hp, vll& depth, vll& par){
    ll res = 1e16;
    for(auto it: chil[i]){
        mark_hp(it, chil, graph, hp, depth, par);
        res= min(res, hp[it]);
    }
    for(auto it: graph[i]){
        if(it!=par[i]){
            res = min(res, depth[it]);
        }
    }
    hp[i] = res;
}
ll find(ll i, vll& par){
    while(par[i]!=-1){
        i = par[i];
    }
    return i;
}
bool isSame(ll i, ll j, vll& par){
    if(find(i, par) == find(j, par)){
        return true;
    }
    else{
        return false;
    }
}
void union_f(ll i, ll j, vll& par, vll& sz){
    j = find(j, par);
    i = find(i, par);
    if(sz[i]<sz[j]){
        swap(i,j);
    }
    par[j] = i;
    sz[i] += sz[j];
}
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        // A common way to combine two hashes.
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // A good combining function is important to avoid collisions.
        // This is a simple but effective one.
        return h1 ^ (h2 << 1); 
    }
};
void solve() {
    ll n;
    cin>>n;
    ll m;
    cin>> m;
    ll k;
    cin>>k;
    vvll graph(n);
    unordered_set<pll, pair_hash>edg;
    unordered_map<pll, ll , pair_hash> ed;
    fl(i,m){
        ll u, v, w;
        cin>>u>>v>>w;
        u--; v--;
        graph[u].pb(v);
        graph[v].pb(u);
        ed[{u,v}] = w;
        ed[{v,u}] = w;
        edg.insert({u,v});
    }
    vvll chil(n);
    vll depth(n);
    vll parent(n);
    parent[0] = -1;
    vector<bool> vis(n,false);
    
    vll par(n, -1);
    vll size(n, 1);

    vpll edge;
    for(auto it: edg){
        edge.pb(it);
    }
    auto cmp = [&](pll& a, pll& b){
        return ed[a]<ed[b];
    };
    sort(edge.begin(), edge.end(), cmp);
    auto it = edge.begin();
    while(it!= edge.end() && ed[*it]<=k){
        it++;
    }
    reverse(edge.begin(), it);
    ll i = 0;
    ll mx2= 0;
    ll fixed2= 0;
    ll mn = 1e16;
    while(i<edge.size()){
        pll a = edge[i];
     
        if(ed[a]>=k){
            mn = min(mn, ed[a]);
        }
        if(!isSame(a.ff, a.ss, par)){
            union_f(a.ff, a.ss, par, size);
            // comps--;
            if(ed[a]<=k){
                mx2 = max(mx2, ed[a]);
            }
            else{
                fixed2 += ed[a]-k;
            }
        }
        i++;
    }
    ll res = 0;
    
     
    if(fixed2==0 && (mx2!=0)){
        res =  min(k-mx2, mn-k);
    }
    else{
        res = fixed2;
    }

    
    // else{
    cout<<res<<endl;
    // }
}
// Allah hu Akbar
// 1110011 1110100 1100001 1101100 1101011 1100101 1110010 100000 1110100 1100101 1110010 1101001 100000 1101101 1100001 1100001 100000 1101011 1101001
int main() {
    Code By Solve
    ll t;
    cin >> t;
    fl(i,t){
        solve();
    }
    
    return 0;
}