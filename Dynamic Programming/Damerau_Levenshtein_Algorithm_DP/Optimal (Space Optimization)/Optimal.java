import java.util.Arrays;

class OperationCosts {
    int insertCost, deleteCost, replaceCost, transposeCost;
    public OperationCosts(int ins, int del, int rep, int trans) {
        insertCost = ins; deleteCost = del; replaceCost = rep; transposeCost = trans;
    }
    public OperationCosts() { this(1,1,1,1); }
}

class DamerauLevenshteinDistance {
    private int min3(int a, int b, int c) { return Math.min(Math.min(a, b), c); }
    private int min4(int a, int b, int c, int d) { return Math.min(Math.min(a, b), Math.min(c, d)); }

    public int distance(String s1, String s2, OperationCosts costs) {
        int m = s1.length(), n = s2.length();
        if (m == 0) return n * costs.insertCost;
        if (n == 0) return m * costs.deleteCost;
        if (m > n) {
            OperationCosts swapped = new OperationCosts(costs.deleteCost, costs.insertCost, costs.replaceCost, costs.transposeCost);
            return distance(s2, s1, swapped);
        }
        int[] prevPrev = new int[m+1], prev = new int[m+1], curr = new int[m+1];
        for (int i=0; i<=m; i++) prev[i] = i * costs.deleteCost;
        for (int j=1; j<=n; j++) {
            curr[0] = j * costs.insertCost;
            for (int i=1; i<=m; i++) {
                if (s1.charAt(i-1) == s2.charAt(j-1)) curr[i] = prev[i-1];
                else {
                    int sub = prev[i-1] + costs.replaceCost;
                    int ins = curr[i-1] + costs.insertCost;
                    int del = prev[i] + costs.deleteCost;
                    if (i>1 && j>1 && s1.charAt(i-1)==s2.charAt(j-2) && s1.charAt(i-2)==s2.charAt(j-1)) {
                        int trans = prevPrev[i-2] + costs.transposeCost;
                        curr[i] = min4(sub, ins, del, trans);
                    } else curr[i] = min3(sub, ins, del);
                }
            }
            prevPrev = Arrays.copyOf(prev, prev.length);
            prev = Arrays.copyOf(curr, curr.length);
        }
        return prev[m];
    }
}

public class Main {
    public static void main(String[] args) {
        DamerauLevenshteinDistance d = new DamerauLevenshteinDistance();
        OperationCosts costs = new OperationCosts(1,1,1,1);
        System.out.println(d.distance("kitten", "sitting", costs)); // 3
        System.out.println(d.distance("martha", "marhta", costs));  // 1
    }
}
