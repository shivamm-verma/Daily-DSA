import java.util.*;

public class Main {

    public static String removeDuplicateLetters(String s) {
        int[] lastIndex = new int[26];
        for (int i = 0; i < s.length(); i++) {
            lastIndex[s.charAt(i) - 'a'] = i;
        }

        boolean[] seen = new boolean[26];
        Stack<Character> stack = new Stack<>();

        for (int i = 0; i < s.length(); i++) {
            int curr = s.charAt(i) - 'a';
            if (seen[curr]) continue;

            while (!stack.isEmpty() && stack.peek() > s.charAt(i) &&
                    i < lastIndex[stack.peek() - 'a']) {
                seen[stack.pop() - 'a'] = false;
            }

            stack.push(s.charAt(i));
            seen[curr] = true;
        }

        StringBuilder sb = new StringBuilder();
        for (char ch : stack) {
            sb.append(ch);
        }

        return sb.toString();
    }

    public static void main(String[] args) {
        String s = "bcabc";
        String result = removeDuplicateLetters(s);
        System.out.println("Result after removing duplicate letters: " + result);
    }
}
