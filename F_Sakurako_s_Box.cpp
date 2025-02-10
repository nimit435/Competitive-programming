#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// Function to calculate (x^y) % MOD
long long mod_pow(long long x, long long y, long long MOD) {
    long long result = 1;
    x = x % MOD;
    while (y > 0) {
        if (y & 1) {
            result = (result * x) % MOD;
        }
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return result;
}

void solve() {
    int t;
    cin >> t;
    int MOD= 1000000007;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        long long sum = 0;
        long long sum_of_squares = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum = (sum + a[i]) % MOD;
            sum_of_squares = (sum_of_squares + a[i] * a[i] % MOD) % MOD;
        }
        
        long long sum_squared = sum * sum % MOD;
        long long sum_of_products = (sum_squared - sum_of_squares + MOD) % MOD;
        
        long long denominator = ((n %MOD)* ((n - 1)%MOD)) % MOD;
        long long denominator_inv = mod_pow(denominator, MOD - 2, MOD);
        
        long long result = sum_of_products * denominator_inv % MOD;
        
        cout << result << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}