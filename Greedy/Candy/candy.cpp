#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> candies(n, 1);

    // Left to right
    for (int i = 1; i < n; ++i) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }

    // Right to left
    for (int i = n - 2; i >= 0; --i) {
        if (ratings[i] > ratings[i + 1]) {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }

    int total = 0;
    for (int c : candies) total += c;
    return total;
}

int main() {
    cout << "Enter ratings separated by spaces: ";
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> ratings;
    int num;
    while (ss >> num) {
        ratings.push_back(num);
    }

    cout << "Minimum candies needed: " << candy(ratings) << endl;
    return 0;
}
