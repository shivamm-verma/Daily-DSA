import java.util.*;

class java code {
    public static int cutRod(int[] price) {
        int n=price.length;
        int[] prev=new int[n+1];
        for(int p=0;p<=n;p++) prev[p]=p*price[0];
        
        for(int i=1;i<n;i++) {
            for(int p=0;p<=n;p++) {
                int notTake=prev[p];
                int take=Integer.MIN_VALUE;
                int rodLen=i+1;
                if(rodLen<=p) take=price[i]+prev[p-rodLen];
                prev[p]=Math.max(notTake,take);
            }
        }
        return prev[n];
    }
    public static void main(String[] args) {
        int[] price={1, 5, 8, 9, 10, 17, 17, 20};
        System.out.println(cutRod(price));
    }
}
