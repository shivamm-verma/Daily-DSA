#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int waysToReachStair(int k) 
    {
        // Variable to store total number of ways to reach stair k
        long num_ways = 0;

        // Loop over possible number of "up" jumps
        // (2^i growth ensures 31 iterations cover all possible stair positions up to ~10^9)
        for (int i = 0; i <= 31; i++)
        {
            // After i jumps, total up moves = i + 1 (since jump starts from 0)
            int num_jumps = i + 1;

            // Total height covered if only "up" moves were taken:
            // sum of powers of 2 up to i = (2^(i+1) - 1)
            // Alice starts from stair 1, so total stairs from 1 = (2^i)
            // stairs_covered_back = total up movement - target stair (k)
            long long stairs_covered_back = (1LL << i) - k;

            // Invalid case:
            // - can't go below stair 0 (stairs_covered_back < 0)
            // - cannot perform more "down" moves than total jumps (stairs_covered_back > num_jumps)
            if (0 > stairs_covered_back || i + 1 < stairs_covered_back)
                continue;

            // Now we need to count number of valid sequences
            // of "up" and "down" operations that result in total displacement (stairs_covered_back)
            // This is a combinatorial problem:
            // Choose "stairs_covered_back" positions to place "down" operations
            // among (num_jumps) total possible move slots.

            // Compute nCr = C(num_jumps, stairs_covered_back)
            long long ways = 1;
            for (int j = 1; j <= stairs_covered_back; j++)
            {
                // Multiplying in iterative form to avoid factorial overflow
                ways *= (num_jumps - j + 1);
                ways = ways / j;
            }

            // Add to total number of ways
            num_ways += ways;
        }

        // Return final result as int
        return (int)num_ways;
    }
};
