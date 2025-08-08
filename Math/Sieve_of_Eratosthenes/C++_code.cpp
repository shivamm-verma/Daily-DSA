// User function Template for C++
class Solution {
  public:
    vector<int> sieveOfEratosthenes(int n) {
        // Step 1: Create a boolean array to mark prime numbers
        vector<bool> isprime(n + 1, true); // isprime[i] = true means i is prime

        // Step 2: Mark 0 and 1 as non-prime
        isprime[0] = false;
        isprime[1] = false;

        // Step 3: Loop from 2 to sqrt(n)
        for (int i = 2; i * i <= n; i++) {
            // If i is still marked as prime
            if (isprime[i]) {
                // Mark all multiples of i as non-prime
                for (int j = 2; j * i <= n; j++) {
                    isprime[i * j] = false;
                }
            }
        }

        // Step 4: Collect all prime numbers into result
        vector<int> ans;
        for (int i = 2; i <= n; i++) {
            if (isprime[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
