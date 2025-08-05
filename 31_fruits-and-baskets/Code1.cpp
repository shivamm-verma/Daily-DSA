#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Code1 {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int maxFruits = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<int> basket;
            int count = 0;
            for (int j = i; j < n; j++) {
                basket.insert(fruits[j]);
                if (basket.size() > 2) {
                    break;
                }
                count++;
            }
            maxFruits = max(maxFruits, count);
        }
        return maxFruits;
    }
};
