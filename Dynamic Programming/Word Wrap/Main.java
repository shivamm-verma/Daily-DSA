import java.util.*;

class Solution {
    
    public int solveWordWrap(int[] arr, int k) {
        int n = arr.length;
        int[] dp = new int[n];   
        int[] ans = new int[n]; 
        dp[n - 1] = 0;
        ans[n - 1] = n - 1;

        
        for (int i = n - 2; i >= 0; i--) {
            int currlen = -1;
            dp[i] = Integer.MAX_VALUE;

            for (int j = i; j < n; j++) {
                currlen += arr[j] + 1;  
                if (currlen > k) break;

                int cost;
                if (j == n - 1) {
                    cost = 0;  
                } else {
                    cost = (k - currlen) * (k - currlen) + dp[j + 1];
                }

                if (cost < dp[i]) {
                    dp[i] = cost;
                    ans[i] = j;
                }
            }
        }

        
        int res = 0;
        int i = 0;
        while (i < n) {
            int pos = 0;
            for (int j = i; j <= ans[i]; j++) {
                pos += arr[j];
            }
            int x = ans[i] - i;
            if (ans[i] + 1 != n) {
                res += (k - x - pos) * (k - x - pos);
            }
            i = ans[i] + 1;
        }
        return res;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        
        int n = sc.nextInt();

        
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        
        int k = sc.nextInt();

        Solution sol = new Solution();
        System.out.println(sol.solveWordWrap(arr, k));
        
        sc.close();
    }
}
