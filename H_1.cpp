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
void dfs(int node, vector<bool> &vis, vector<int> adj[], stack<int> &st){
    vis[node]=true;
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it, vis, adj, st);
        }
    }
    st.push(node);
}
void dfs2(int node, vector<bool> &vis, vector<int> adjT[], int counter, vector<int> &assigned){
    vis[node]=true;
    for(auto it: adjT[node]){
        if(!vis[it]){
            dfs2(it, vis, adjT, counter, assigned);
        }
    }
    assigned[node]=counter;

}
bool twoSAT(vector<int> adj[], int n){
    vector<bool> vis(2*n, false);
    stack<int> st;
    for(int i=0; i<2*n; i++){
        if(!vis[i]){
            dfs(i,vis,adj,st);
        }
    }
    vector<int> adjT[2*n];
    for(int i=0; i<2*n; i++){
        vis[i]=0;
        for(auto it: adj[i]){
            adjT[it].pb(i);
        }
    }
    int scc=0;
    vector<int> assigned(2*n,0);
    while(!st.empty()){
        int node= st.top();
        st.pop();
        if(!vis[node]){
            scc++;
            dfs2(node, vis, adjT, scc, assigned);
        }
    }
    // fl(i, assigned.size()){
    //     cout<<assigned[i]<<" ";

    // }
    // cout<<endl;
    for(int i=0; i<n; i++){
        if(assigned[2*i]==assigned[2*i+1]){
            return false;
        }
    }
    return true;
    
}
int helper(int a){
    if(a>0){
        return 2*(a-1);
    }
    else{
        return -2*(a)-1;
    }
}
void solve() {
    int n;
    cin >> n;
    vector<int> matrix[3];
    fl(i,3){
        fl(j,n){
            int v;
            cin>>v;
            matrix[i].pb(v);
        }
    }
    vector<int> adj[2*n];
    fl(i,n){
        int a=matrix[0][i];
        int b= matrix[1][i];
        int c= matrix[2][i];
        adj[helper(-1*a)].pb(helper(b));
        adj[helper(-1*b)].pb(helper(a));
        adj[helper(-1*a)].pb(helper(c));
        adj[helper(-1*c)].pb(helper(a));
        adj[helper(-1*b)].pb(helper(c));
        adj[helper(-1*c)].pb(helper(b));
    }
    // fl(i,2*n){
    //     cout<<"{ ";
    //     fl(j,adj[i].size()){
    //         cout<<adj[i][j]<<" ";
    //     }
    //     cout<<"}, ";
    // }
    if(twoSAT(adj,n)){
        py
    }
    else{
        pn
    }

}
//Main
int main() {
    Code By Solve
    ll t;
    cin >> t;
    fl(i, t) {
        solve();
    }
    return 0;
}