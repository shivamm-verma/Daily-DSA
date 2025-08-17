import java.util.*;

class DLResult {
    int cost;
    List<String> operations;
    DLResult() { this.cost = 0; this.operations = new ArrayList<>(); }
    DLResult(int cost, List<String> operations) { this.cost = cost; this.operations = operations; }
}

class OperationCosts {
    int insertCost, deleteCost, replaceCost, transposeCost;  
    OperationCosts(int ins, int del, int rep, int trans) { 
        this.insertCost = ins; this.deleteCost = del; this.replaceCost = rep; this.transposeCost = trans;  
    }
    OperationCosts() { this(1,1,1,1); }
}

public class Main {
    private static int minimumCost(int a, int b, int c) { return Math.min(a, Math.min(b, c)); }
    private static int minimumCost(int a, int b, int c, int d) { return Math.min(Math.min(a, b), Math.min(c, d)); }

    private static int damerauLevenshteinCostOnly(String str1, String str2, int i, int j, OperationCosts costs) {
        if (i == str1.length()) return (str2.length() - j) * costs.insertCost;
        if (j == str2.length()) return (str1.length() - i) * costs.deleteCost;
        if (str1.charAt(i) == str2.charAt(j)) return damerauLevenshteinCostOnly(str1, str2, i + 1, j + 1, costs);
        int insertCost = costs.insertCost + damerauLevenshteinCostOnly(str1, str2, i, j + 1, costs);
        int deleteCost = costs.deleteCost + damerauLevenshteinCostOnly(str1, str2, i + 1, j, costs);
        int replaceCost = costs.replaceCost + damerauLevenshteinCostOnly(str1, str2, i + 1, j + 1, costs);
        if (i + 1 < str1.length() && j + 1 < str2.length() && str1.charAt(i) == str2.charAt(j + 1) && str1.charAt(i + 1) == str2.charAt(j)) {
            int transposeCost = costs.transposeCost + damerauLevenshteinCostOnly(str1, str2, i + 2, j + 2, costs);
            return minimumCost(insertCost, deleteCost, replaceCost, transposeCost);
        }
        return minimumCost(insertCost, deleteCost, replaceCost);
    }

    private static DLResult damerauLevenshteinCostAndOperation(String str1, String str2, int i, int j, OperationCosts costs) {
        if (i == str1.length()) {
            List<String> ops = new ArrayList<>(); int totalCost = 0;
            for (int k = j; k < str2.length(); k++) { ops.add("Insert '" + str2.charAt(k) + "'"); totalCost += costs.insertCost; }
            return new DLResult(totalCost, ops);
        }
        if (j == str2.length()) {
            List<String> ops = new ArrayList<>(); int totalCost = 0;
            for (int k = i; k < str1.length(); k++) { ops.add("Delete '" + str1.charAt(k) + "'"); totalCost += costs.deleteCost; }
            return new DLResult(totalCost, ops);
        }
        if (str1.charAt(i) == str2.charAt(j)) {
            DLResult res = damerauLevenshteinCostAndOperation(str1, str2, i + 1, j + 1, costs);
            res.operations.add(0, "Match '" + str1.charAt(i) + "'"); return res;
        }
        DLResult insertOp = damerauLevenshteinCostAndOperation(str1, str2, i, j + 1, costs);
        insertOp.cost += costs.insertCost; insertOp.operations.add(0, "Insert '" + str2.charAt(j) + "'");
        DLResult deleteOp = damerauLevenshteinCostAndOperation(str1, str2, i + 1, j, costs);
        deleteOp.cost += costs.deleteCost; deleteOp.operations.add(0, "Delete '" + str1.charAt(i) + "'");
        DLResult replaceOp = damerauLevenshteinCostAndOperation(str1, str2, i + 1, j + 1, costs);
        replaceOp.cost += costs.replaceCost; replaceOp.operations.add(0, "Replace '" + str1.charAt(i) + "' with '" + str2.charAt(j) + "'");
        if (i + 1 < str1.length() && j + 1 < str2.length() && str1.charAt(i) == str2.charAt(j + 1) && str1.charAt(i + 1) == str2.charAt(j)) {
            DLResult transposeOp = damerauLevenshteinCostAndOperation(str1, str2, i + 2, j + 2, costs);
            transposeOp.cost += costs.transposeCost; transposeOp.operations.add(0, "Transpose '" + str1.charAt(i) + str1.charAt(i + 1) + "'");
            if (insertOp.cost <= deleteOp.cost && insertOp.cost <= replaceOp.cost && insertOp.cost <= transposeOp.cost) return insertOp;
            else if (deleteOp.cost <= insertOp.cost && deleteOp.cost <= replaceOp.cost && deleteOp.cost <= transposeOp.cost) return deleteOp;
            else if (replaceOp.cost <= insertOp.cost && replaceOp.cost <= deleteOp.cost && replaceOp.cost <= transposeOp.cost) return replaceOp;
            else return transposeOp;
        }
        if (insertOp.cost <= deleteOp.cost && insertOp.cost <= replaceOp.cost) return insertOp;
        else if (deleteOp.cost <= insertOp.cost && deleteOp.cost <= replaceOp.cost) return deleteOp;
        else return replaceOp;
    }

    public static void main(String[] args) {
        OperationCosts costs = new OperationCosts(1,1,1,1);
        String s1 = "kitten", s2 = "sitting";
        System.out.println("Edit Distance: " + damerauLevenshteinCostOnly(s1, s2, 0, 0, costs));
        DLResult res = damerauLevenshteinCostAndOperation(s1, s2, 0, 0, costs);
        System.out.println("Operations:"); for (String op : res.operations) System.out.println(op);
    }
}
