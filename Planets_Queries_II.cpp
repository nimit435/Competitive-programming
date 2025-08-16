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
void solve() {
    ll n;
    cin>>n;
    ll q;
    cin>>q;
    vll succ(n);
    vvll bef(n);
    fl(i,n){
        cin>>succ[i];
        succ[i]--;
        bef[succ[i]].pb(i);
    }
    vll cycle_id(n, -2);
    // printvec(cycle_id);
    vector<map<ll,ll>> cycles;
    fl(i,n){
        if(cycle_id[i]!=-2){
            continue;
        }
        vll path;
        path.pb(i);
        ll at = i;
        cycle_id[at] = -3;
        while(cycle_id[succ[at]]==-2){
            at = succ[at];
            cycle_id[at] = -3;
            path.pb(at);
        }
        map<ll, ll> cycle;
        bool in_cycle = false;
        for(auto it: path){
            in_cycle = in_cycle || (succ[at]==it);
            if(in_cycle){
                cycle[it] = cycle.size();
            }
            cycle_id[it] = in_cycle ? cycles.size() : -1;
        }
        cycles.pb(cycle);
    }
    vll cycle_dist(n, 0);
    // printvec(cycle_dist);
    
    
    fl(i,n){
        if(cycle_id[succ[i]]==-1 || cycle_id[i]!=-1){
            continue;
        }
        queue<ll> q;
        for(auto it: bef[i]){
            q.push(it);
        }
        cycle_dist[i] = 1;
        while(!q.empty()){
            ll a = q.front();
            q.pop();
            cycle_dist[a] = cycle_dist[succ[a]]+1;
            for(auto it: bef[a]){
                q.push(it);
            }
        }
    }
    ll mx = ceil(log2(n));
    vvll dp(n, vll(mx+1));
    fl(i,n){
        dp[i][0] = succ[i];
    }
    for(int j=1; j<=mx; j++){
        fl(i,n){
            dp[i][j]= dp[dp[i][j-1]][j-1];
        }
    }
    auto jump = [&](ll pos, ll dist){
        for(ll j = mx ; j>=0; j--){
            if((dist&(1LL<<j))!=0){
                pos = dp[pos][j];
            }
        }
        return pos;
    };
    // printvec(cycle_id);
    // for(auto it: cycle_dist){
    //     cout<<it<<" ";

    // }
    // cout<<endl;
    // printvec(cycle_dist);

    fl(j , q){
        ll u, v; 
        cin>>u>>v;
        u--;
        v--;
        if(cycle_id[dp[u][mx]]!=cycle_id[dp[v][mx]]){
            cout<<-1<<endl;
            continue;
        }
        if(cycle_id[u]!=-1 || cycle_id[v]!=-1){
            if(cycle_id[v]==-1 ){
                cout<<-1<<endl;
                continue;
            }
            
            ll dis = cycle_dist[u];
            ll u_head = jump(u, dis);
            map<ll,ll>& cyc = cycles[cycle_id[u_head]];
            // for(auto it: cyc){
            //     cout<<it<<" ";
            // }
            // cout<<endl;
            ll u_ind = cyc[u_head];
            ll v_ind = cyc[v];
            ll ad = u_ind <= v_ind ? v_ind - u_ind : cyc.size() - (u_ind - v_ind);
            cout<<ad+dis<<endl;
            continue;
        }
        else{
            if(cycle_dist[u]<cycle_dist[v]){
                cout<<-1<<endl;
                continue;
            }
            else{
                ll diff = cycle_dist[u] - cycle_dist[v];
                if(jump(u, diff)==v){
                    cout<<diff<<endl;
                }
                else{
                    cout<<-1<<endl;
                }
            }
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