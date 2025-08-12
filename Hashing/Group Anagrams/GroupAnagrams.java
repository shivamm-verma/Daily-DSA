import java.util.*;

public class GroupAnagrams {
    public static List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> map = new HashMap<>();

        for (String s : strs) {
            char[] chars = s.toCharArray();
            Arrays.sort(chars);
            String key = new String(chars);

            map.computeIfAbsent(key, k -> new ArrayList<>()).add(s);
        }

        return new ArrayList<>(map.values());
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Size of array: ");
        int n = sc.nextInt();
        sc.nextLine(); 

        System.out.print("Enter space-separated strings: ");
        String[] strs = sc.nextLine().split(" ");

        if (strs.length != n) {
            System.out.println(" Expected " + n + " strings, but got " + strs.length);
        } else {
            List<List<String>> result = groupAnagrams(strs);
            System.out.println("Grouped Anagrams:");
            for (List<String> group : result) {
                System.out.println(group);
            }
        }
    }
}