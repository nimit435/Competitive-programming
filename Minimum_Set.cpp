#include <iostream>
using namespace std;

struct TrieNode {
    TrieNode* child[2];
    TrieNode() {
        child[0] = child[1] = nullptr;
    }
};

void insert(TrieNode* root, int num, int bitlen) {
    TrieNode* node = root;
    for (int b = bitlen - 1; b >= 0; --b) {
        int bit = (num >> b) & 1;
        if (!node->child[bit]) node->child[bit] = new TrieNode();
        node = node->child[bit];
    }
}

int min_xor(TrieNode* root, int num, int bitlen) {
    int ans = 0;
    TrieNode* node = root;
    for (int b = bitlen - 1; b >= 0; --b) {
        int bit = (num >> b) & 1;
        if (node->child[bit]) {
            node = node->child[bit];
        } else {
            node = node->child[1 - bit];
            ans |= (1 << b);
        }
    }
    return ans;
}

void collect(TrieNode* root, int prefix, int depth, vector<int>& nums) {
    if (!root) return;
    if (depth < 0) {
        nums.push_back(prefix);
        return;
    }
    if (root->child[0]) collect(root->child[0], prefix, depth - 1, nums);
    if (root->child[1]) collect(root->child[1], prefix | (1 << depth), depth - 1, nums);
}

long long dfs_mst(TrieNode* node, int bitlen) {
    if (!node) return 0;
    if (!node->child[0] && !node->child[1]) return 0;
    if (!node->child[0]) return dfs_mst(node->child[1], bitlen - 1);
    if (!node->child[1]) return dfs_mst(node->child[0], bitlen - 1);

    long long cost_left = dfs_mst(node->child[0], bitlen - 1);
    long long cost_right = dfs_mst(node->child[1], bitlen - 1);

    // Find minimum cross-edge
    vector<int> nums;
    collect(node->child[0], 0, bitlen - 1, nums);

    int min_bridge = INT_MAX;
    for (int x : nums) {
        min_bridge = min(min_bridge, min_xor(node->child[1], x, bitlen - 1));
    }

    return cost_left + cost_right + min_bridge;
}

long long mst_xor(int N) {
    int bitlen = 32 - __builtin_clz(N);  // number of bits to represent N
    TrieNode* root = new TrieNode();
    for (int i = 1; i <= N; i++) {
        insert(root, i, bitlen);
    }
    return dfs_mst(root, bitlen);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        cout << mst_xor(N) << "\n";
    }
    return 0;
}
