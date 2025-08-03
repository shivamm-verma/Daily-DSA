import java.util.*;

public class Main {

    static String[] keypad = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    public static void solve(String digits, int index, String path, List<String> result) {
        if (index == digits.length()) {
            result.add(path);
            return;
        }

        String letters = keypad[digits.charAt(index) - '0'];
        for (char ch : letters.toCharArray()) {
            solve(digits, index + 1, path + ch, result);
        }
    }

    public static List<String> letterCombinations(String digits) {
        List<String> result = new ArrayList<>();
        if (digits.isEmpty()) return result;

        solve(digits, 0, "", result);
        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String digits = sc.next();

        List<String> combos = letterCombinations(digits);
        for (String s : combos) {
            System.out.print(s + " ");
        }
    }
}
