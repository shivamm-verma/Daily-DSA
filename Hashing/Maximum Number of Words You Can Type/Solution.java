import java.util.*;

public class Solution {
    public int canBeTypedWords(String text, String brokenLetters) {
        Set<Character> broken = new HashSet<>();
        for (char ch : brokenLetters.toCharArray()) {
            broken.add(ch);
        }

        String[] words = text.split(" ");
        int count = 0;

        for (String word : words) {
            boolean canType = true;
            for (char ch : word.toCharArray()) {
                if (broken.contains(ch)) {
                    canType = false;
                    break;
                }
            }
            if (canType) count++;
        }

        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the sentence: ");
        String text = sc.nextLine();

        System.out.print("Enter broken letters (no spaces): ");
        String brokenLetters = sc.nextLine();

        Solution sol = new Solution();
        int result = sol.canBeTypedWords(text, brokenLetters);

        System.out.println("You can type " + result + " word(s) without using broken letters.");
    }
}