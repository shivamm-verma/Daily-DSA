#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool find132pattern(vector<int>& nums) {
    int n = nums.size();
    stack<int> st;
    int third = INT_MIN;
    for (int i = n - 1; i >= 0; i--) {
        if (nums[i] < third)
            return true;
        while (!st.empty() && nums[i] > st.top()) {
            third = st.top();
            st.pop();
        }
        st.push(nums[i]);
    }
    return false;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << (find132pattern(nums) ? "true" : "false") << endl;
    return 0;
}
