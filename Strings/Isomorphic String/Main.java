import java.util.*;

public class Main {
    public static boolean isIsomorphic(String s, String t) {
        if (s.length() != t.length()) return false;

        int[] mapST = new int[256];
        int[] mapTS = new int[256];

        for (int i = 0; i < s.length(); i++) {
            char a = s.charAt(i);
            char b = t.charAt(i);

            if (mapST[a] == 0 && mapTS[b] == 0) {
                mapST[a] = b;
                mapTS[b] = a;
            } else {
                if (mapST[a] != b || mapTS[b] != a) return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String t = sc.next();
        System.out.println(isIsomorphic(s, t) ? "true" : "false");
    }
}
