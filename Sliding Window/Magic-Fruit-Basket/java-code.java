import java.util.*;

public class MagicFruitBasket {
    public static int totalFruits(int[] arr) {
        Map<Integer, Integer> count = new HashMap<>();
        int left = 0, maxFruits = 0;

        for (int right = 0; right < arr.length; right++) {
            count.put(arr[right], count.getOrDefault(arr[right], 0) + 1);

            while (count.size() > 2) {
                count.put(arr[left], count.get(arr[left]) - 1);
                if (count.get(arr[left]) == 0) {
                    count.remove(arr[left]);
                }
                left++;
            }

            maxFruits = Math.max(maxFruits, right - left + 1);
        }
        return maxFruits;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of fruits:");
        int n = sc.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter fruits array:");
        for (int i = 0; i < n; i++) arr[i] = sc.nextInt();

        System.out.println("Maximum fruits collected: " + totalFruits(arr));
        sc.close();
    }
}
