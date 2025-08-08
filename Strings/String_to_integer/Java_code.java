import java.util.Scanner;
class Java_code {
    public static int myAtoi(String s) {
        int i = 0, n = s.length(), sign = 1, ans = 0;
        while (i < n && s.charAt(i) == ' ') {
            i++;
        }
        if (i < n && (s.charAt(i) == '+' || s.charAt(i) == '-')) {
            sign = (s.charAt(i) == '-') ? -1 : 1;
            i++;
        }
        while (i < n && s.charAt(i) >= '0' && s.charAt(i) <= '9') {
            int digit = s.charAt(i) - '0';
            if(ans>(Integer.MAX_VALUE - digit)/10){
                return (sign ==1)?Integer.MAX_VALUE:Integer.MIN_VALUE;
            }
            ans = ans * 10 + digit;
            i++;
        }
        return ans * sign;
    }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        String s=sc.nextLine();
        System.out.println(myAtoi(s));
    }
}