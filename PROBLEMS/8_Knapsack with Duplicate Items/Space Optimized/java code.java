import java.util.*;

class java code {
    private static int knapsack(int[] wt,int[] val,int capacity,int n) {
        int[] prev=new int[capacity+1];
        for(int w=0;w<=capacity;w++) prev[w]=((int)(w/wt[0]))*val[0];

        for(int i=1;i<n;i++) {
            for(int w=0;w<=capacity;w++) {
                int notTake=prev[w];
                int take=Integer.MIN_VALUE;
                if(wt[i]<=w) take=val[i]+prev[w-wt[i]];
                prev[w]=Math.max(notTake, take);
            }
        }
        return prev[capacity];
    }
    public static void main(String[] args) {
        int[] val={6,1,7,7};
        int[] wt={1,3,4,5};
        int capacity=8;
        System.out.println(knapsack(wt,val,capacity,wt.length));
    }    
}
