#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int top = 0, left = 0;
    int bottom = n - 1, right = m - 1;
    vector<int> ans;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            ans.push_back(matrix[top][i]);
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            ans.push_back(matrix[i][right]);
        }
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> result = spiralOrder(matrix);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
