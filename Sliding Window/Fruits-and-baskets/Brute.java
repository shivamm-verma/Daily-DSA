import java.util.*;
class Brute {
    public int totalFruit(int[] fruits) {
        int n=fruits.length;
        int maxFruits=0;
        for (int i=0;i<n;i++) {
            Set<Integer> basket=new HashSet<>();
            int count=0;
            for (int j=i;j<n;j++) {
                basket.add(fruits[j]);
                if(basket.size()>2) {
                    break;
                }
                count++;
            }
            maxFruits = Math.max(maxFruits, count);
        }
        return maxFruits;
    }
}

