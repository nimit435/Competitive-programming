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
string traceback(vvll& depth, ll si, ll sj, ll i , ll j){
    ll curr = depth[i][j];
    vpll path;
    ll n = depth.size();

    path.pb(mp(i,j));
    while(curr!=0){
        if(i>0 && depth[i-1][j]==curr-1){
            path.pb(mp(i-1,j));
            i--;
            curr--;
        }
        else if(j>0 && depth[i][j-1]==curr-1){
            path.pb(mp(i,j-1));
            j--;
            curr--;
        }
        else if(i<n-1 && depth[i+1][j]== curr-1){
            path.pb(mp(i+1,j));
            i++;
            curr--;
        }
        else{
            path.pb(mp(i,j+1));
            j++;
            curr--;
        }

    }
    string res = "";
    // printvec(path);
    for(int i= path.size()-2; i>=0; i--){
        ll ni = path[i].ff;
        ll nj = path[i].ss;
        ll pi = path[i+1].ff;
        ll pj = path[i+1].ss;
        if(ni == pi-1){
            res += 'U';
        }
        else if(ni == pi+1){
            res += 'D';
        }
        else if(nj == pj-1){
            res+= 'L';
        }
        else{
            res+= 'R';
        }
    }
    return res;
}  
void solve() {
    ll n;
    cin>>n;
    ll m;
    cin>>m;
    vector<string> graph(n);
    fl(i,n){
        cin>>graph[i];
    }
    vector<vector<bool>> vis(n, vector<bool>(m,false));
    queue<pll> q;
    vvll depth(n, vll(m,-1));
    ll si = -1;
    ll sj = -1;
    fl(i,n){
        fl(j,m){
            if(graph[i][j]=='A'){
                si = i;
                sj = j;
            }
            if(graph[i][j]=='M'){
                depth[i][j] = 0;
                vis[i][j] = true;
                q.push(mp(i,j));
            }
        }
    }

    while(!q.empty()){
        pll a = q.front();
        q.pop();
        ll i = a.ff;
        ll j = a.ss;
        if(i>0 && graph[i-1][j]!='#' && !vis[i-1][j]){
            depth[i-1][j] = depth[i][j]+1;
            vis[i-1][j] = true;
            q.push(mp(i-1, j));
        }
        if(j>0 && graph[i][j-1]!='#' && !vis[i][j-1]){
            depth[i][j-1] = depth[i][j]+1;
            vis[i][j-1] = true;
            q.push(mp(i, j-1));
        }
        if(i<n-1 && graph[i+1][j]!='#' && !vis[i+1][j]){
            depth[i+1][j] = depth[i][j]+1;
            vis[i+1][j] = true;
            q.push(mp(i+1, j));
        }
        if(j<m-1 && graph[i][j+1]!='#' && !vis[i][j+1]){
            depth[i][j+1] = depth[i][j]+1;
            vis[i][j+1] = true;
            q.push(mp(i, j+1));
        }
    }
    vvll deptha(n, vll(m,-1));
    deptha[si][sj] = 0;
    vector<vector<bool>> visa(n, vector<bool>(m,false));
    visa[si][sj] = true;
    q.push(mp(si, sj));
    while(!q.empty()){
        pll a = q.front();
        q.pop();
        ll i = a.ff;
        ll j = a.ss;
        if(i>0 && graph[i-1][j]!='#' && !visa[i-1][j]){
            deptha[i-1][j] = deptha[i][j]+1;
            visa[i-1][j] = true;
            q.push(mp(i-1, j));
        }
        if(j>0 && graph[i][j-1]!='#' && !visa[i][j-1]){
            deptha[i][j-1] = deptha[i][j]+1;
            visa[i][j-1] = true;
            q.push(mp(i, j-1));
        }
        if(i<n-1 && graph[i+1][j]!='#' && !visa[i+1][j]){
            deptha[i+1][j] = deptha[i][j]+1;
            visa[i+1][j] = true;
            q.push(mp(i+1, j));
        }
        if(j<m-1 && graph[i][j+1]!='#' && !visa[i][j+1]){
            deptha[i][j+1] = deptha[i][j]+1;
            visa[i][j+1] = true;
            q.push(mp(i, j+1));
        }
    }
    vvll depthf(n, vll(m,-1));
    depthf[si][sj] = 0;
    vector<vector<bool>> visf(n, vector<bool>(m,false));
    visf[si][sj] = true;
    q.push(mp(si, sj));
   
    while(!q.empty()){
        pll a = q.front();
        q.pop();
        ll i = a.ff;
        ll j = a.ss;
        // cout<<a<<endl;
        if(i>0 && graph[i-1][j]!='#' && !visf[i-1][j] && (depth[i-1][j]>deptha[i-1][j] || depth[i-1][j]==-1)){
            depthf[i-1][j] = depthf[i][j]+1;
            visf[i-1][j] = true;
            q.push(mp(i-1, j));
        }
        if(j>0 && graph[i][j-1]!='#' && !visf[i][j-1] && (depth[i][j-1]>deptha[i][j-1]|| depth[i][j-1]==-1)){
            depthf[i][j-1] = depthf[i][j]+1;
            visf[i][j-1] = true;
            q.push(mp(i, j-1));
        }
        if(i<n-1 && graph[i+1][j]!='#' && !visf[i+1][j] && (depth[i+1][j]>deptha[i+1][j] || depth[i+1][j] == -1)){
            depthf[i+1][j] = depthf[i][j]+1;
            visf[i+1][j] = true;
            q.push(mp(i+1, j));
        }
        if(j<m-1 && graph[i][j+1]!='#' && !visf[i][j+1] && (depth[i][j+1]>deptha[i][j+1] || depth[i][j+1] == -1)){
            depthf[i][j+1] = depthf[i][j]+1;
            visf[i][j+1] = true;
            q.push(mp(i, j+1));
        }
    }
  
    fl(j,m){
        if(graph[0][j]!='#' && depthf[0][j]!=-1){
            string st = traceback( depthf, si, sj, 0, j);
            cout<<"YES"<<endl;
            cout<<st.size()<<endl;
            cout<<st<<endl;
            return;
        }
    }
    fl(j,m){
        if(graph[n-1][j]!='#' && depthf[n-1][j]!=-1){
            string st = traceback( depthf, si, sj, n-1, j);
            cout<<"YES"<<endl;
            cout<<st.size()<<endl;
            cout<<st<<endl;
            return;
        }
    }
    for(int i=1; i<=n-2; i++){
        if(graph[i][0]!='#' && depthf[i][0]!=-1){
            string st = traceback( depthf, si, sj, i, 0);
            cout<<"YES"<<endl;
            cout<<st.size()<<endl;
            cout<<st<<endl;
            return;
        }
        if(graph[i][m-1]!='#' && depthf[i][m-1]!=-1){
            string st = traceback( depthf, si, sj, i, m-1);
            cout<<"YES"<<endl;
            cout<<st.size()<<endl;
            cout<<st<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}
// Allah hu Akbar
// 1110011 1110100 1100001 1101100 1101011 1100101 1110010 100000 1110100 1100101 1110010 1101001 100000 1101101 1100001 1100001 100000 1101011 1101001
int main() {
    Code By Solve
    solve();
    return 0;
}