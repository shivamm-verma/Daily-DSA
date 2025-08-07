import java.util.*;

public class Main {
     public static void reverseString(char[] s) {
        int l=0,r=s.length-1;
        while(l<r){
            char temp=s[l];
            s[l]=s[r];
            s[r]=temp;
            l++;
            r--;
        }
    }
    public static void main(String[] args) {
        String str="hello";
        char[] ch=str.toCharArray();
        reverseString(ch);
        for(char chr:ch) System.out.print(chr); //Output : "olleh"
    }
}