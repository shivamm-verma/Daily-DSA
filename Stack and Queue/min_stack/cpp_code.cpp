#include <stack>
using namespace std;

class MinStack {
    stack<int> s, minS;

public:
    MinStack() {}

    void push(int val) {
        s.push(val);
        if (minS.empty() || val <= minS.top())
            minS.push(val);
    }

    void pop() {
        if (s.top() == minS.top())
            minS.pop();
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return minS.top();
    }
};
