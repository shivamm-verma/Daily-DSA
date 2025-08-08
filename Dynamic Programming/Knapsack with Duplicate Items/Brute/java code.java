import java.util.*;

class java code {
    private static int knapsack(int ind,int[] wt,int[] val,int capacity) {
        if(ind==0) return ((int)(capacity/wt[0]))*val[0];
        int notTake=knapsack(ind-1, wt, val, capacity);
        int take=Integer.MIN_VALUE;
        if(wt[ind]<=capacity) take=val[ind]+knapsack(ind, wt, val, capacity-wt[ind]);
        return Math.max(notTake, take);
    }
    public static void main(String[] args) {
        int[] val={6,1,7,7};
        int[] wt={1,3,4,5};
        int capacity=8;
        System.out.println(knapsack(wt.length-1,wt,val,capacity));
    }    
}