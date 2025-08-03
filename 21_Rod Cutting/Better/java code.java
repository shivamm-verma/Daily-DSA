import java.util.*;

class java code {
    public static int cutRod(int[] price,int ind,int n,int[][] dp) {
       if(ind==0) return n*price[0];
       if(dp[ind][n]!=-1) return dp[ind][n];
       int notTake=cutRod(price, ind-1, n,dp);
       int take=Integer.MIN_VALUE;
       int rodLen=ind+1;
       if(rodLen<=n) take=price[ind]+cutRod(price, ind, n-rodLen,dp);
       return dp[ind][n]=Math.max(take, notTake);
    }
    public static void main(String[] args) {
        int[] price={1, 5, 8, 9, 10, 17, 17, 20};
        int n=price.length;
        int[][] dp=new int[n][n+1];
        for (int row[] : dp)
            Arrays.fill(row, -1);
        System.out.println(cutRod(price,n-1,n,dp));
    }
}
