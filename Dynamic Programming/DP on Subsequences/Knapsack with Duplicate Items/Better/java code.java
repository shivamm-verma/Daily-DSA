import java.util.*;

class java code {
    private static int knapsack(int ind,int[] wt,int[] val,int capacity,int[][] dp) {
        if(ind==0) return ((int)(capacity/wt[0]))*val[0];
        if(dp[ind][capacity]!=-1) return dp[ind][capacity];
        int notTake=knapsack(ind-1, wt, val, capacity,dp);
        int take=Integer.MIN_VALUE;
        if(wt[ind]<=capacity) take=val[ind]+knapsack(ind, wt, val, capacity-wt[ind],dp);
        return dp[ind][capacity]=Math.max(notTake, take);
    }
    public static void main(String[] args) {
        int[] val={6,1,7,7};
        int[] wt={1,3,4,5};
        int capacity=8;
        int[][] dp=new int[wt.length][capacity+1];
        for (int row[] : dp)
            Arrays.fill(row, -1);
        System.out.println(knapsack(wt.length-1,wt,val,capacity,dp));
    }    
}
