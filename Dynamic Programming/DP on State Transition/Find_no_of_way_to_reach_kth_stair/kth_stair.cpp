#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int waysToReachStair(int k) 
    {
        // Variable to store total number of ways to reach stair k
        long num_ways = 0;
        // Loop over possible number of "up" jumps covering all cases for combination.
        for (int i = 0; i <= 31; i++)
        {
            // After i jumps, total up moves = i + 1
            int num_jumps = i + 1;
            long long stairs_covered_back = (1LL << i) - k;

            if (0 > stairs_covered_back || i + 1 < stairs_covered_back)
            continue;
            // Now we need to count number of valid sequences of "up" and "down" operations that result in total displacement
            // among total possible move slots. now Compute nCr using its formula.
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
        return (int)num_ways;
    }
};
