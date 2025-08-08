import java.util.*;

class LAResult {
    int cost;
    List<String> operations;
    
    public LAResult() {
        this.cost = 0;
        this.operations = new ArrayList<>();
    }
    
    public LAResult(int cost, List<String> operations) {
        this.cost = cost;
        this.operations = operations;
    }
}

class OperationCosts {
    int insertCost;
    int deleteCost;
    int replaceCost;
    
    public OperationCosts() {
        this.insertCost = 1;
        this.deleteCost = 1;
        this.replaceCost = 1;
    }
    
    public OperationCosts(int ins, int del, int rep) {
        this.insertCost = ins;
        this.deleteCost = del;
        this.replaceCost = rep;
    }
}

public class Main {
    
    private static int minimumCost(int a, int b, int c) {
        return Math.min(a, Math.min(b, c));
    }
    
    // Recursion Method - Return only the cost
    // Time Complexity: O(3^N)
    // Space Complexity: O(N) {stack}
    private static int levenshteinCostOnly(String str1, String str2, int i, int j, OperationCosts costs) {
        
        if (i == str1.length()) {
            return (str2.length() - j) * costs.insertCost;
        }
        if (j == str2.length()) {
            return (str1.length() - i) * costs.deleteCost;
        }
        
        if (str1.charAt(i) == str2.charAt(j)) {
            return levenshteinCostOnly(str1, str2, i + 1, j + 1, costs);
        }
        
        int insertCost = costs.insertCost + levenshteinCostOnly(str1, str2, i, j + 1, costs);
        int deleteCost = costs.deleteCost + levenshteinCostOnly(str1, str2, i + 1, j, costs);
        int replaceCost = costs.replaceCost + levenshteinCostOnly(str1, str2, i + 1, j + 1, costs);
        
        return minimumCost(insertCost, deleteCost, replaceCost);
    }
    
    // Recursion Method - Return cost + operations
    // Time Complexity: O(3^N)
    // Space Complexity: O(N^2) {stack + operations}
    private static LAResult levenshteinCostAndOperation(String str1, String str2, int i, int j, OperationCosts costs) {
        
        if (i == str1.length()) {
            List<String> ops = new ArrayList<>();
            int totalCost = 0;
            for (int k = j; k < str2.length(); k++) {
                ops.add("Insert '" + str2.charAt(k) + "' (cost: " + costs.insertCost + ")");
                totalCost += costs.insertCost;
            }
            return new LAResult(totalCost, ops);
        }
        
        if (j == str2.length()) {
            List<String> ops = new ArrayList<>();
            int totalCost = 0;
            for (int k = i; k < str1.length(); k++) {
                ops.add("Delete '" + str1.charAt(k) + "' (cost: " + costs.deleteCost + ")");
                totalCost += costs.deleteCost;
            }
            return new LAResult(totalCost, ops);
        }
        
        if (str1.charAt(i) == str2.charAt(j)) {
            LAResult res = levenshteinCostAndOperation(str1, str2, i + 1, j + 1, costs);
            res.operations.add(0, "Match '" + str1.charAt(i) + "' (cost: 0)");
            return res;
        }
        
        LAResult insertOp = levenshteinCostAndOperation(str1, str2, i, j + 1, costs);
        insertOp.cost += costs.insertCost;
        insertOp.operations.add(0, "Insert '" + str2.charAt(j) + "' (cost: " + costs.insertCost + ")");
        
        LAResult deleteOp = levenshteinCostAndOperation(str1, str2, i + 1, j, costs);
        deleteOp.cost += costs.deleteCost;
        deleteOp.operations.add(0, "Delete '" + str1.charAt(i) + "' (cost: " + costs.deleteCost + ")");
        
        LAResult replaceOp = levenshteinCostAndOperation(str1, str2, i + 1, j + 1, costs);
        replaceOp.cost += costs.replaceCost;
        replaceOp.operations.add(0, "Replace '" + str1.charAt(i) + "' with '" + str2.charAt(j) + "' (cost: " + costs.replaceCost + ")");
        
        if (insertOp.cost <= deleteOp.cost && insertOp.cost <= replaceOp.cost) {
            return insertOp;
        } else if (deleteOp.cost <= insertOp.cost && deleteOp.cost <= replaceOp.cost) {
            return deleteOp;
        } else {
            return replaceOp;
        }
    }
    
    private static OperationCosts getCosts() {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("\n--- Operation Cost Configuration ---");
        System.out.print("Do all operations have the same cost? (yes=1 / no=0): ");
        int sameCostChoice = scanner.nextInt();
        
        if (sameCostChoice == 1) {
            System.out.print("Enter the cost for all operations (insert, delete, replace): ");
            int uniformCost = scanner.nextInt();
            System.out.println("All operations will have cost: " + uniformCost + "\n");
            return new OperationCosts(uniformCost, uniformCost, uniformCost);
        } else {
            System.out.print("Enter the cost for insert operation: ");
            int insertCost = scanner.nextInt();
            System.out.print("Enter the cost for delete operation: ");
            int deleteCost = scanner.nextInt();
            System.out.print("Enter the cost for replace operation: ");
            int replaceCost = scanner.nextInt();
            
            return new OperationCosts(insertCost, deleteCost, replaceCost);
        }
    }
    
    private static int editDistance(String s1, String s2, OperationCosts costs) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Do you want detailed operations? (yes=1 / no=0)");
        System.out.print("Enter your choice (1/0): ");
        int flag = scanner.nextInt();
        
        if (flag == 1) {
            LAResult result = levenshteinCostAndOperation(s1, s2, 0, 0, costs);
            System.out.println("\nOperations to convert '" + s1 + "' to '" + s2 + "':");
            for (String op : result.operations) {
                System.out.println(" - " + op);
            }
            System.out.println();
            return result.cost;
        }
        
        return levenshteinCostOnly(s1, s2, 0, 0, costs);
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("This is a Java program to calculate the Levenshtein distance with custom operation costs.\n\n");
        
        System.out.print("Enter the number of string pairs you want to process: ");
        int numInputs = scanner.nextInt();
        System.out.println();
        
        for (int i = 1; i <= numInputs; i++) {
            System.out.println("\n\n\n ***** ***** ***** ***** Pair " + i + " ***** ***** ***** ***** \n");
            
            // Get operation costs configuration
            OperationCosts costs = getCosts();
            
            System.out.print("Enter the first string (The original string): ");
            String str1 = scanner.next();
            System.out.print("Enter the second string (String to convert to): ");
            String str2 = scanner.next();
            
            System.out.println("\nResults for { Pair " + i + " }");
            int res = editDistance(str1, str2, costs);
            System.out.println("Total Edit Distance for Pair " + i + ": " + res);
        }
        
        scanner.close();
    }
}