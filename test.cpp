
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <algorithm>
#include <iostream>


using namespace std;

vector<string> generateAllExpressions(const string& s, int left, int right, map<pair<int, int>, vector<string>>& memo) {
    if (memo.find({left, right}) != memo.end()) {
        return memo[{left, right}];
    }
    vector<string> res;
    bool isSingleNumber = true;
    for (int i = left; i <= right; ++i) {
        if (s[i] == '+' || s[i] == '*') {
            isSingleNumber = false;
            break;
        }
    }
    if (isSingleNumber) {
        res.push_back(s.substr(left, right - left + 1));
        memo[{left, right}] = res;
        return res;
    }
    for (int i = left; i <= right; ++i) {
        if (s[i] == '+' || s[i] == '*') {
            vector<string> leftExprs = generateAllExpressions(s, left, i - 1, memo);
            vector<string> rightExprs = generateAllExpressions(s, i + 1, right, memo);
            for (const string& l : leftExprs) {
                for (const string& r : rightExprs) {
                    string expr;
                    expr += l;
                    expr += s[i];
                    expr += r;
                    res.push_back(expr);
                    // Also consider adding parentheses around the entire expression
                    // if it's not the original expression and not already parenthesized
                    if (left != 0 || right != s.size() - 1) {
                        bool alreadyParenthesized = (expr.front() == '(' && expr.back() == ')');
                        if (!alreadyParenthesized) {
                            string parenExpr = "(" + expr + ")";
                            res.push_back(parenExpr);
                        }
                    }
                }
            }
        }
    }
    memo[{left, right}] = res;
    return res;
}

vector<string> generateExpressionEncodings(const string& s) {
    map<pair<int, int>, vector<string>> memo;
    vector<string> all = generateAllExpressions(s, 0, s.size() - 1, memo);
    vector<string> result;
    map<string, bool> seen;
    for (const string& expr : all) {
        if (seen.find(expr) == seen.end()) {
            seen[expr] = true;
            // Exclude the original expression without any parentheses
            if (expr != s) {
                // Also exclude expressions with redundant parentheses
                bool redundant = false;
                if (expr.front() == '(' && expr.back() == ')') {
                    string inner = expr.substr(1, expr.size() - 2);
                    if (inner.front() == '(' && inner.back() == ')') {
                        redundant = true;
                    }
                }
                if (!redundant) {
                    result.push_back(expr);
                }
            }
        }
    }
    return result;
}
int main(){
    string s;
    cin>>s;

    const string k = s;
    vector<string> vs;
    vs = generateExpressionEncodings(k);
    for(string st: vs){
        cout<<st<<endl;
    }
}
 // namespace expression_encoder