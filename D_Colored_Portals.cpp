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
    ll n;//1-100000
    cin >> n;
    ll q;
    cin>>q;//1-10000
    /*
    BG: 0, BR: 1, BY: 2, GR: 3, GY: 4, RY: 5
    */
    map<string, int> hm;
    hm["BG"]=0;
    hm["BR"]=1;
    hm["BY"]=2;
    hm["GR"]=3;
    hm["GY"]=4;
    hm["RY"]=5;

    vector<string> vec(n);
    fl(i,n){
        cin>>vec[i];
    }
    vector<vector<ll> > lcit(n, vector<ll>(6,-1));
    vector<vector<ll> > rcit(n, vector<ll>(6,-1));
    vector<int> portal(6,-1);
    portal[hm[vec[0]]]=0;
    for(int i=1; i<n; i++){
        fl(j,6){
            lcit[i][j]= portal[j];
        }
        portal[hm[vec[i]]]= i;
    }
    fl(i,6){
        portal[i]=-1;
    }
    portal[hm[vec[n-1]]]=n-1;
    for(int i=n-2; i>=0; i--){
        fl(j,6){
            rcit[i][j]= portal[j];
        }
        portal[hm[vec[i]]]=i;
    }
    fl(i,q){
        ll a;
        ll b;
        cin>>a;
        cin>>b;
        if(a==b){
            cout<<0<<endl;
        }
        else{
            if(a>b){
                ll temp= a;
                a= b;
                b= temp;        
            }
            a--;
            b--;

            if(((hm[vec[a]]+hm[vec[b]])%5!=0) || (hm[vec[a]]==hm[vec[b]])){
                ll res= b-a;
                cout<<res<<endl;
            }
            else{
                ll nope= hm[vec[a]];
                ll ans= INT_MAX;
                for(int j=0; j<6; j++){
                    if(j!=nope && j!=(5-nope) && rcit[a][j]!=-1){
                        ans= min(ans, rcit[a][j]);
                    }
                }
                if(ans<b){
                    ll res= b-a;
                    cout<<res<<endl;
                }
                else{
                    ll res1;
                    if(ans!=INT_MAX){
                        res1 = ans-a+ ans-b;
                    }
                    else{
                        res1= INT_MAX;
                    }
                    ans= -1;
                    for(int j=0; j<6; j++){
                        if(j!=nope && j!=(5-nope) && lcit[a][j]!=-1){
                            ans= max(ans, lcit[a][j]);
                        }
                    }
                    if(ans!=-1){
                        res1= min(res1, (a-ans+b-ans));
                    }
                    if(res1==INT_MAX){
                        cout<<-1<<endl;
                    }
                    else{
                        cout<<res1<<endl;
                    }
                }
            }
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
//num-5 timeout-2000 test-hilo.txt