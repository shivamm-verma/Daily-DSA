import java.util.*;
public class Main{
    // optimized code in java
    static int maxProduct(int[] arr, int n) {
        int currmax = arr[0];
        int currmin = arr[0];
        int maxp = arr[0];
        
        for(int i=1; i<n; i++){
            int temp = Math.max(arr[i], Math.max(arr[i]*currmax, arr[i]*currmin));
            currmin = Math.min(arr[i], Math.min(arr[i]*currmax, arr[i]*currmin));
            currmax = temp;
            maxp = Math.max(maxp, currmax);
        }
        return maxp;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        int res = maxProduct(arr, n);
        System.out.println(res);
        sc.close();
    }
}