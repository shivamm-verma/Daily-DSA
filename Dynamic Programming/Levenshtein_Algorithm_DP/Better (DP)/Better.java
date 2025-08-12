import java.util.*;

public class WeightedLevenshteinDistance {
    
    static class LAResult {
        int cost;
        List<String> operations;
        
        public LAResult() {
            this.cost = 0;
            this.operations = new ArrayList<>();
        }
        
        public LAResult(int cost, List<String> operations) {
            this.cost = cost;
            this.operations = new ArrayList<>(operations);
        }
    }
    
    static class OperationCosts {
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
    private static Scanner scanner = new Scanner(System.in);
    
    private static int minimumCost(int a, int b, int c) {
        return Math.min(a, Math.min(b, c));
    }
    
    private static OperationCosts getCosts() {
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
    
    // DP Matrix Method with different operational costs - Return only the cost
    // Time Complexity: O(M * N)    - traversing the matrix
    // Space Complexity: O(M * N)   - 2D matrix
    public static int levenshteinWeightedCostOnly(String str1, String str2, OperationCosts costs) {
        int m = str1.length();
        int n = str2.length();
        
        int[][] dpMatrix = new int[m + 1][n + 1];
        
        for (int i = 0; i <= m; i++) {
            dpMatrix[i][0] = i * costs.deleteCost;
        }
        
        for (int j = 0; j <= n; j++) {
            dpMatrix[0][j] = j * costs.insertCost;
        }
        
        // Fill the dp matrix
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                    dpMatrix[i][j] = dpMatrix[i - 1][j - 1];
                } else {
                    int ins = dpMatrix[i][j - 1] + costs.insertCost;
                    int del = dpMatrix[i - 1][j] + costs.deleteCost;
                    int rep = dpMatrix[i - 1][j - 1] + costs.replaceCost;
                    
                    dpMatrix[i][j] = minimumCost(ins, del, rep);
                }
            }
        }
        
        return dpMatrix[m][n];
    }
    
    // Overloaded version for backward compatibility
    public static int levenshteinWeightedCostOnly(String str1, String str2, int insertCost, int deleteCost, int replaceCost) {
        OperationCosts costs = new OperationCosts(insertCost, deleteCost, replaceCost);
        return levenshteinWeightedCostOnly(str1, str2, costs);
    }
    
    // DP Matrix Method with different operational costs - Return the cost and operations
    // Time Complexity: O(M * N)            Traversing the matrix
    // Space Complexity: O(2(M * N))       2D matrix + operations vector
    public static LAResult levenshteinWeightedCostAndOperation(String str1, String str2, OperationCosts costs) {
        int m = str1.length();
        int n = str2.length();
        
        LAResult[][] dpMatrix = new LAResult[m + 1][n + 1];
        
        // Initialize matrix
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                dpMatrix[i][j] = new LAResult();
            }
        }
        
        for (int i = 0; i <= m; i++) {
            dpMatrix[i][0].cost = i * costs.deleteCost;
            for (int k = 0; k < i; k++) {
                dpMatrix[i][0].operations.add("DELETE '" + str1.charAt(k) + "'");
            }
        }
        
        for (int j = 0; j <= n; j++) {
            dpMatrix[0][j].cost = j * costs.insertCost;
            for (int k = 0; k < j; k++) {
                dpMatrix[0][j].operations.add("INSERT '" + str2.charAt(k) + "'");
            }
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                    dpMatrix[i][j].cost = dpMatrix[i - 1][j - 1].cost;
                    dpMatrix[i][j].operations = new ArrayList<>(dpMatrix[i - 1][j - 1].operations);
                    dpMatrix[i][j].operations.add("MATCH '" + str1.charAt(i - 1) + "'");
                } else {
                    int ins = dpMatrix[i][j - 1].cost + costs.insertCost;
                    int del = dpMatrix[i - 1][j].cost + costs.deleteCost;
                    int rep = dpMatrix[i - 1][j - 1].cost + costs.replaceCost;
                    
                    int minVal = minimumCost(ins, del, rep);
                    dpMatrix[i][j].cost = minVal;
                    
                    if (minVal == rep) {
                        dpMatrix[i][j].operations = new ArrayList<>(dpMatrix[i - 1][j - 1].operations);
                        dpMatrix[i][j].operations.add("REPLACE '" + str1.charAt(i - 1) + "' with '" + str2.charAt(j - 1) + "'");
                    } else if (minVal == del) {
                        dpMatrix[i][j].operations = new ArrayList<>(dpMatrix[i - 1][j].operations);
                        dpMatrix[i][j].operations.add("DELETE '" + str1.charAt(i - 1) + "'");
                    } else {
                        dpMatrix[i][j].operations = new ArrayList<>(dpMatrix[i][j - 1].operations);
                        dpMatrix[i][j].operations.add("INSERT '" + str2.charAt(j - 1) + "'");
                    }
                }
            }
        }
        
        return dpMatrix[m][n];
    }
    
    // Overloaded version for backward compatibility
    public static LAResult levenshteinWeightedCostAndOperation(String str1, String str2, int insertCost, int deleteCost, int replaceCost) {
        OperationCosts costs = new OperationCosts(insertCost, deleteCost, replaceCost);
        return levenshteinWeightedCostAndOperation(str1, str2, costs);
    }
    
    public static int editDistance(String s1, String s2, OperationCosts costs) {
        System.out.print("Do you want detailed operations? (yes=1 / no=0): ");
        int flag = scanner.nextInt();
        
        if (flag == 1) {
            LAResult result = levenshteinWeightedCostAndOperation(s1, s2, costs);
            System.out.println("\nOperations to convert '" + s1 + "' to '" + s2 + "':");
            for (String op : result.operations) {
                System.out.println(" - " + op);
            }
            System.out.println();
            return result.cost;
        }
        
        return levenshteinWeightedCostOnly(s1, s2, costs);
    }
    
    // Overloaded version for backward compatibility
    public static int editDistance(String s1, String s2, int ci, int cd, int cs) {
        OperationCosts costs = new OperationCosts(ci, cd, cs);
        return editDistance(s1, s2, costs);
    }
    
    public static void main(String[] args) {
        System.out.println("This is a Java program to calculate the Weighted Levenshtein distance.");
        
        System.out.print("\n\nEnter the number of string pairs you want to process: ");
        int numInputs = scanner.nextInt();
        System.out.println();
        
        for (int i = 1; i <= numInputs; i++) {
            System.out.println("\n\n\n ***** ***** ***** ***** Pair " + i + " ***** ***** ***** ***** \n");
            System.out.print("Enter the first string (The original string): ");
            String str1 = scanner.next();
            System.out.print("Enter the second string (String to convert to): ");
            String str2 = scanner.next();
            
            OperationCosts costs = getCosts();
            
            System.out.println("\nResults for { Pair " + i + " }");
            int res = editDistance(str1, str2, costs);
            System.out.println("Levenshtein Distance for Pair " + i + ": " + res);
        }
        
        scanner.close();
    }
}