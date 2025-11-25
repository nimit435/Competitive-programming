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
// class Segtree{
//     int size;
//     vector<ll> tree;
//     public:
//     Segtree(vll& vec){
//         size = vec.size();
//         int n = size;
//         tree.resize(2*n);
//         copy(vec.begin(),vec.end(), tree.begin() + size);
//         for(int i=size-1; i>0; i--){
//             tree[i] = min(tree[2*i], tree[(2*i) +1]);
//         }
//     }
//     ll get(ll l , ll r){
//         l += size;
//         r += size;
//         ll mx = 1e18;
//         while(l<=r){
//             if(l%2==1){
//                 mx = min(mx, tree[l]);
//                 l++;
//             }
//             if(r%2==0){
//                 mx = min(mx, tree[r]);
//                 r--;
//             }
//             l /= 2;
//             r /= 2;
//         }
//         return mx;
//     }
// };
// ll getind(ll x, ll r, map<ll, vll>& ind){
//     int n = ind[x].size();
//     if(n==1){
//         return ind[x][0];
//     }
//     int left = 0; // ind[x][left] <= r
//     int right = n-1; // ind[x][left]>r
//     if(ind[x][right]<=r){
//         return ind[x][right];
//     }
//     while(right - left >1){
//         int mid = (left )+ ((right-left)/2);
//         if(ind[x][mid]<=r){
//             left = mid;
//         }
//         else{
//             right = mid;
//         }
//     }
//     return ind[x][left];
// }
void solve() {
    ll n;
    cin>>n;
    ll q;
    cin>>q;
    vll vec(n);
    fl(i,n){
        cin>>vec[i];
    }
    vll pref(n+1,0);
    vll xr(n+1, 0);
    for(int i=1; i<=n; i++){
        pref[i]= pref[i-1]+vec[i-1];
        xr[i] = xr[i-1]^vec[i-1];
    }
    // printvec(pref);
    // printvec(xr);

    vll helper(n+1);
    map<ll, vll> ind;
    for(int i=0;i<=n; i++){
        helper[i] = pref[i]-xr[i];
        ind[helper[i]].push_back(i);
    }
    ll L, R;
    cin>>L>>R;
    // Segtree tr(helper);
    int lfin = L;
    int rfin = L;
    ll best = 0;
    // printvec(helper);
    // for(auto it: ind){
    //     cout<<it.ff<<": "<<endl;
    //     printvec(it.second);
    // }
    // for(int r = R; r>=L; r--){
    //     ll val = tr.get(L-1, r-1);
    //     cout<<r<<" "<<val<<endl;
    //     if(helper[r]- val > best){
    //         ll i = getind(val, r-1, ind);
    //         cout<<": "<<r<<" "<<i<<endl;
    //         rfin = r;
    //         lfin = i+1;
    //         best = helper[r] - val;
    //         // cout<<r<<" :::"<<endl;
    //     }
    //     else if(helper[r]- val == best){
    //         ll i = getind(val, r-1, ind);
    //         if(r-(i+1)+1<= (rfin - lfin +1)){
    //             rfin = r;
    //             lfin = i+1;
    //         }
    //         // cout<<i<<" "<<r<<" :::"<<endl;
    //     }
    //     cout<<"::"<< rfin<<" "<<lfin<<endl;
    // }
    // cout<<lfin<<" "<<rfin<<endl;
    for(int i=L; i<=R; i++){
        ll mx = (pref[R] - pref[i-1]) - (xr[R]^xr[i-1]);
        // if(i==1){
        //     ll a = pref[R] - pref[i-1];
        //     ll b = (xr[R]^xr[i-1]);
        //     cout<<a-b<<endl;
        //     cout<<pref[R] - pref[i-1]<<endl;
        //     cout<<(xr[R]^xr[i-1])<<endl;

        //     cout<<mx<<"::"<<R<<endl;
        // }
        if(mx>best){
            int left = i; // f(i, left) < mx;
            int right = R; // f(i, right) = mx
            if(pref[left]-pref[i-1] - (xr[left]^xr[i-1])==mx){
                lfin = i;
                rfin = i;
                continue;
            }
            while(right-left>1){
                int mid = left + ((right-left)/2);
                if(pref[mid] - pref[i-1] - (xr[mid]^xr[i-1])!=mx){
                    left = mid;
                }
                else{
                    right = mid;
                }
            }
            lfin = i;
            rfin = right;
            best = mx;

        }
        else if(mx==best){
            int left = i; // f(i, left) < mx;
            int right = R; // f(i, right) = mx
            if(pref[left]-pref[i-1] - (xr[left]^xr[i-1])==mx){
                lfin = i;
                rfin = i;
                continue;
            }
            while(right-left>1){
                int mid = left + ((right-left)/2);
                if(pref[mid] - pref[i-1] - (xr[mid]^xr[i-1])!=mx){
                    left = mid;
                }
                else{
                    right = mid;
                }
            }
            if(right-i+1<rfin-lfin+1){
                rfin = right;
                lfin = i;
            }
        }
    }
    cout<<lfin<<" "<<rfin<<endl;
    // cout<<pref[rfin]-pref[lfin-1] - (xr[rfin]^xr[lfin-1])<<endl;
    // cout<<pref[12]-pref[1-1] - (xr[12]^xr[1-1])<<endl;

}
// Allah hu Akbar
// 1110011 1110100 1100001 1101100 1101011 1100101 1110010 100000 1110100 1100101 1110010 1101001 100000 1101101 1100001 1100001 100000 1101011 1101001
int main() {
    Code By Solve
    ll t;
    cin >> t;
    fl(i, t) {
        solve();
    }
    return 0;
}