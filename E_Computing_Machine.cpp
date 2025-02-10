#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include<limits.h>
#include <string>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <cstring>
// #include <bits/stdc++.h>

using namespace std;

//Speed
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Solve cout.tie(NULL);

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
bool isPrime(ll n) { if (n <= 1) return false; if (n <= 3) return true; if (n % 2 == 0 || n % 3 == 0) return false; for (int i = 5; i * i <= n; i = i + 6) if (n % i == 0 || n % (i + 2) == 0) return false; return true; }
bool isPowerOfTwo(int n) { if (n == 0) return false; return (ceil(log2(n)) == floor(log2(n))); }
bool isPerfectSquare(ll x) { if (x >= 0) { ll sr = sqrt(x); return (sr * sr == x); } return false; }

//Code
void solve() {
    ll n;
    cin >> n;
    string s;
    string t;
    cin>> s;
    cin>> t;
    ll q;
    cin>>q;
    vpll vec(q);
    fl(i,q){
        ll l;
        ll r;
        cin>>l;
        cin>>r;
        vec[i]= mp(l,r);
    }
    string s1= s;
    string t1= t;

    for(int i=0; i<n-2; i++){
        if(s[i]==s[i+2] && s[i]=='0'){
            t1[i+1]= '1';
        }
    }
    for(int i=0; i<n-2; i++){
        if(t1[i]==t1[i+2] && t1[i]=='1'){
            s1[i+1]= '1';
        }
    }
    vll pre(n);
    if(s1[0]=='1'){
        pre[0]=1;
    }
    else{
        pre[0]=0;
    }
    for(int i=1; i<n; i++){
        if(s1[i]=='1'){
            pre[i]=pre[i-1]+1;
        }
        else{
            pre[i]=pre[i-1];
        }
    }
    // cout<<s1<<endl;
    fl(i,q){
        ll l= vec[i].first-1;
        ll r= vec[i].second-1;
        if(r-l+1<5){
            string s2= s;
            string t2= t;
            for(int i=l; i<r-1; i++){
                if(s[i]==s[i+2] && s[i]=='0'){
                    t2[i+1]= '1';
                }
            }
            for(int i=l; i<r-1; i++){
                if(t2[i]==t2[i+2] && t2[i]=='1'){
                    s2[i+1]= '1';
                }
            }
            ll count= 0;
            // cout<<s2<<endl;
            for(int i=l; i<=r; i++){
                if(s2[i]=='1'){
                    count++;
                }
            }
            cout<<count<<endl;
        }
        else{
            ll count= 0;
            if(s[l]=='1'){
                count++;
            }
            if(s[l+1]=='1'){
                count++;
            }
            if(s[r]=='1'){
                count++;
            }
            if(s[r-1]=='1'){
                count++;
            }
            if(s[l+1]=='0'){
                if(t[l]=='1'){
                    if(t[l+2]=='1'){
                        count++;
                    }
                    else{
                        if(s[l+3]=='0'){
                            count++;
                        }
                    }
                }
            }
            if(s[r-1]=='0'){
                if(t[r]=='1'){
                    if(t[r-2]=='1'){
                        count++;
                    }
                    else{
                        if(s[r-3]=='0'){
                            count++;
                        }
                    }
                }
            }
            count+= (pre[r-2]-pre[l+1]);
            cout<<count<<endl;

        }
    }

}
// Allah hu Akbar
int main() {
    Code By Solve
    ll t;
    cin >> t;
    fl(i, t) {
        solve();
    }
    return 0;
}