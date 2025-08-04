import java.util.*;

class java code {
    public static int longestCommonSubsequence(String text1, String text2,int ind1,int ind2) {
        if(ind1<=0 || ind2<0) return 0;
        if(text1.charAt(ind2)==text2.charAt(ind2)) return 1+longestCommonSubsequence(text1, text2, ind1-1, ind2-1);
        else return Math.max(longestCommonSubsequence(text1, text2, ind1-1, ind2), longestCommonSubsequence(text1, text2, ind1, ind2-1));
    }
    public static void main(String[] args) {
        String text1="abcde";
        String text2="ace";
        System.out.println(longestCommonSubsequence(text1, text2,text1.length()-1,text2.length()-1));
    }
}
