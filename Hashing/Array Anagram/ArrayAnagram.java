import java.util.HashMap;

public class ArrayAnagram {
    public static boolean isArrayAnagram(int[] arr1, int[] arr2) {
        if (arr1.length != arr2.length) return false;

        HashMap<Integer, Integer> freq = new HashMap<>();

        // Count frequencies in arr1
        for (int num : arr1) {
            freq.put(num, freq.getOrDefault(num, 0) + 1);
        }

        // Subtract frequencies using arr2
        for (int num : arr2) {
            if (!freq.containsKey(num)) return false;
            freq.put(num, freq.get(num) - 1);
            if (freq.get(num) == 0) freq.remove(num);
        }

        return freq.isEmpty();
    }

    public static void main(String[] args) {
        int[] arr1 = {1, 2, 3};
        int[] arr2 = {3, 2, 1};
        int[] arr3 = {1, 2, 2};
        int[] arr4 = {2, 1, 1};

        System.out.println(isArrayAnagram(arr1, arr2)); // true
        System.out.println(isArrayAnagram(arr3, arr4)); // false
    }
}
