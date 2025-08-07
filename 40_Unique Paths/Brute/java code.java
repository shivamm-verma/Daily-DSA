import java.util.*;

class java_code {
     public static int uniquePaths(int i, int j) {
        if(i==0 && j==0) return 1;
        if(i<0||j<0) return 0;
        int up=uniquePaths(i-1, j);
        int left=uniquePaths(i, j-1);
        return up+left;
    }
    public static void main(String[] args) {
        int m=3,n=7;
        System.out.println(uniquePaths(m-1, n-1));
    }    
}
