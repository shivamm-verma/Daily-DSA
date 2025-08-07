import java.util.*;

class java code {
    public static int cutRod(int[] price,int ind,int n) {
       if(ind==0) return n*price[0];
       int notTake=cutRod(price, ind-1, n);
       int take=Integer.MIN_VALUE;
       int rodLen=ind+1;
       if(rodLen<=n) take=price[ind]+cutRod(price, ind, n-rodLen);
       return Math.max(take, notTake);
    }
    public static void main(String[] args) {
        int[] price={1, 5, 8, 9, 10, 17, 17, 20};
        int n=price.length;
        System.out.println(cutRod(price,n-1,n));
    }
}
