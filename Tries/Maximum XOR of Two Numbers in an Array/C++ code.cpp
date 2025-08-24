#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    Node* links[2];

    Node() {
        links[0] = links[1] = nullptr;
    }

    bool isSet(int bit) {
        return links[bit] != nullptr;
    }

    Node* get(int bit) {
        return links[bit];
    }

    void put(int bit, Node* node) {
        links[bit] = node;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->isSet(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num) {
        Node* node = root;
        int maxi = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->isSet(1 - bit)) {
                maxi |= (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }
        return maxi;
    }
};

int findMaximumXOR(vector<int>& nums) {
    Trie trie;
    int res = 0;
    for (int i = nums.size() - 1; i >= 0; i--) {
        trie.insert(nums[i]);
        res = max(res, trie.getMax(nums[i]));
    }
    return res;
}

int main() {
    vector<int> nums = {3, 10, 5, 25, 2, 8};
    cout << findMaximumXOR(nums) << endl; // Output: 28
    return 0;
}
