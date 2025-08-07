import java.util.*;

class java_code {
     public static int uniquePaths(int i, int j,int[][] dp) {
        if(i==0 && j==0) return 1;
        if(i<0||j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=uniquePaths(i-1, j,dp);
        int left=uniquePaths(i, j-1,dp);
        return up+left;
    }
    public static void main(String[] args) {
        int m=3,n=7;
        int[][] dp=new int[m][n];
        for (int row[] : dp)
            Arrays.fill(row, -1);
        System.out.println(uniquePaths(m-1, n-1,dp));
    }    
}
