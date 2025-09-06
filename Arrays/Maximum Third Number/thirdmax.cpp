#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int thirdMax(vector<int>& nums) {
    long max1 = LONG_MIN, max2 = LONG_MIN, max3 = LONG_MIN;

    for (int num : nums) {
        if (num == max1 || num == max2 || num == max3) continue;

        if (num > max1) {
            max3 = max2;
            max2 = max1;
            max1 = num;
        } else if (num > max2) {
            max3 = max2;
            max2 = num;
        } else if (num > max3) {
            max3 = num;
        }
    }

    return (max3 == LONG_MIN) ? max1 : max3;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int result = thirdMax(nums);
    cout << "Third maximum number is: " << result << endl;

    return 0;
}
