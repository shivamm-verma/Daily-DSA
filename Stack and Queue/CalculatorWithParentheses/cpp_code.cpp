#include <bits/stdc++.h>
using namespace std;

int prec(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void applyOp(deque<char>& ops, deque<long long>& nums) {
    char op = ops.back(); ops.pop_back();
    long long b = nums.back(); nums.pop_back();
    long long a = nums.back(); nums.pop_back();
    long long res = 0;
    if (op == '+') res = a + b;
    else if (op == '-') res = a - b;
    else if (op == '*') res = a * b;
    else res = a / b; // trunc toward 0 for integers
    nums.push_back(res);
}

long long calculate(const string &s) {
    deque<char> ops;
    deque<long long> nums;
    int i = 0, n = s.size();
    while (i < n) {
        char c = s[i];
        if (c == ' ') { i++; continue; }
        if (isdigit(c)) {
            long long num = 0;
            while (i < n && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            nums.push_back(num);
            continue;
        }
        if (c == '(') ops.push_back(c);
        else if (c == ')') {
            while (!ops.empty() && ops.back() != '(') applyOp(ops, nums);
            ops.pop_back(); // pop '('
        } else {
            while (!ops.empty() && prec(ops.back()) >= prec(c)) applyOp(ops, nums);
            ops.push_back(c);
        }
        i++;
    }
    while (!ops.empty()) applyOp(ops, nums);
    return nums.back();
}

int main() {
    cout << calculate("3+2*2") << "\n";                 // 7
    cout << calculate(" (1+(4+5+2)-3)+(6+8) ") << "\n"; // 23
    cout << calculate("14-3/2") << "\n";                // 13
    return 0;
}
