import java.util.*;

class java code {
    public static int longestCommonSubsequence(String text1, String text2) {
        int n=text1.length();
        int m=text2.length();
        int[] prev=new int[m+1];

        for(int j=0;j<=m;j++) prev[j]=0;
        for(int i=1;i<=n;i++) {
            int[] cur=new int[m+1];
            for(int j=1;j<=m;j++) {
                if(text1.charAt(i-1)==text2.charAt(j-1)) cur[j]=1+prev[j-1];
                else cur[j]=Math.max(prev[j],cur[j-1]);
            }
            prev=cur;
        }
        return prev[m];
    }
    public static void main(String[] args) {
        String text1="abcde";
        String text2="ace";
        System.out.println(longestCommonSubsequence(text1, text2));
    }
}
