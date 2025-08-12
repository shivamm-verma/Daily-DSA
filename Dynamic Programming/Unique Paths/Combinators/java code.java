import java.util.*;

class java_code {
    public static int uniquePaths(int m, int n) {
        int N=n+m-2;
        int r=m-1;
        double res=1;
        for(int i=1;i<=r;i++) {
            res=res*(N-r+i)/i;
        }
        return (int)res;   
    }
    public static void main(String[] args) {
        int m=3,n=7;
        System.out.println(uniquePaths(m, n));
    }    
}
