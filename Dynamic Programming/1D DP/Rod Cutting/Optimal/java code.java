import java.util.*;

class java code {
    public static int cutRod(int[] price) {
        int n=price.length;
        int[][] dp=new int[n][n+1];
        for(int p=0;p<=n;p++) dp[0][p]=p*price[0];
        
        for(int i=1;i<n;i++) {
            for(int p=0;p<=n;p++) {
                int notTake=dp[i-1][p];
                int take=Integer.MIN_VALUE;
                int rodLen=i+1;
                if(rodLen<=p) take=price[i]+dp[i][p-rodLen];
                dp[i][p]=Math.max(notTake,take);
            }
        }
        return dp[n-1][n];
    }
    public static void main(String[] args) {
        int[] price={1, 5, 8, 9, 10, 17, 17, 20};
        System.out.println(cutRod(price));
    }
}
