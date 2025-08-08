import java.util.*;

class Solution {
    public List<Integer> sieveOfEratosthenes(int n) {
        // Step 1: Create a boolean array where true means prime
        boolean[] isprime = new boolean[n + 1];
        Arrays.fill(isprime, true); // Initially assume all numbers are prime

        // Step 2: 0 and 1 are not primes
        isprime[0] = false;
        isprime[1] = false;

        // Step 3: Iterate from 2 to sqrt(n)
        for (int i = 2; i * i <= n; i++) {
            if (isprime[i]) {
                // Mark multiples of i as non-prime
                for (int j = 2; i * j <= n; j++) {
                    isprime[i * j] = false;
                }
            }
        }

        // Step 4: Collect all primes in a list
        List<Integer> primes = new ArrayList<>();
        for (int i = 2; i <= n; i++) {
            if (isprime[i]) {
                primes.add(i);
            }
        }
        return primes;
    }
}
