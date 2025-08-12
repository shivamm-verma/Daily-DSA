import java.util.Scanner;
import java.util.Arrays;

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

class LevenshteinDistance {
    
    private int minimumCost(int a, int b) {
        return (a <= b) ? a : b;
    }
    
    private int minimumCost(int a, int b, int c) {
        return Math.min(Math.min(a, b), c);
    }
    
    private void printVector(int[] vec, String label) {
        System.out.print(label + ": [");
        for (int i = 0; i < vec.length; i++) {
            System.out.printf("%3d", vec[i]);
            if (i < vec.length - 1) System.out.print(",");
        }
        System.out.println(" ]");
    }
    
    // DP Vector Method with different operational costs - Return only the cost
    // Time Complexity: O(M * N) - traversing over str1 for each letter in str2
    // Space Complexity: O(2(min(M,N))) - 2 vectors
    public int levenshteinSpaceOptimizedCost(String str1, String str2, OperationCosts costs) {
        int m = str1.length();
        int n = str2.length();
        
        if (m == 0) return n * costs.insertCost;
        if (n == 0) return m * costs.deleteCost;
        
        System.out.println("\nString 1: \"" + str1 + "\" (length: " + m + ")");
        System.out.println("String 2: \"" + str2 + "\" (length: " + n + ")");
        System.out.println("Costs - Insert: " + costs.insertCost + ", Delete: " + costs.deleteCost + ", Replace: " + costs.replaceCost);
        
        // str1 should be the shorter string for space optimization
        if (m > n) {
            System.out.println("\nSwapping strings for space optimization...");
            OperationCosts swappedCosts = new OperationCosts(costs.deleteCost, costs.insertCost, costs.replaceCost);
            return levenshteinSpaceOptimizedCost(str2, str1, swappedCosts);
        }
        
        int[] prev = new int[m + 1];
        int[] curr = new int[m + 1];
        
        System.out.println("\n\nInitializing base cases for deletions:");
        for (int i = 0; i <= m; i++) {
            prev[i] = i * costs.deleteCost;
        }
        
        System.out.println("prev[i] (cost of deleting 'i' characters)");
        printVector(prev, "Initial prev vector");
        
        for (int j = 1; j <= n; j++) {
            System.out.println("\n**** Processing column " + j + " (character '" + str2.charAt(j-1) + "') ****");
            
            curr[0] = j * costs.insertCost;
            System.out.println("curr[0] = " + curr[0] + " (cost of inserting " + j + " characters)");
            
            for (int i = 1; i <= m; i++) {
                System.out.print("Comparing '" + str1.charAt(i-1) + "' with '" + str2.charAt(j-1) + "':");
                
                if (str1.charAt(i-1) == str2.charAt(j-1)) {
                    curr[i] = prev[i-1];
                    System.out.println("  MATCH! No cost added. curr[" + i + "] = prev[" + (i-1) + "] = " + curr[i]);
                } else {
                    int substituteOP = prev[i-1] + costs.replaceCost;
                    int insertOP = curr[i-1] + costs.insertCost;
                    int delOP = prev[i] + costs.deleteCost;
                    
                    System.out.print("  NO MATCH.");
                    
                    curr[i] = minimumCost(substituteOP, insertOP, delOP);
                    System.out.print("    Minimum cost: " + curr[i]);
                    
                    if (curr[i] == substituteOP) System.out.print(" (substitute_OP)");
                    else if (curr[i] == insertOP) System.out.print(" (insert_OP)");
                    else System.out.print(" (delete)");
                    System.out.println();
                }
            }
            
            printVector(curr, "Current curr vector");
            
            prev = Arrays.copyOf(curr, curr.length);
        }
        
        return prev[m];
    }
    
    // Overloaded version with individual cost parameters for backward compatibility
    public int levenshteinSpaceOptimizedCost(String str1, String str2, int insertCost, int deleteCost, int substituteCost) {
        OperationCosts costs = new OperationCosts(insertCost, deleteCost, substituteCost);
        return levenshteinSpaceOptimizedCost(str1, str2, costs);
    }
    
    public int levenshteinSpaceOptimizedCost(String str1, String str2) {
        OperationCosts costs = new OperationCosts(); // default costs of 1
        return levenshteinSpaceOptimizedCost(str1, str2, costs);
    }
}

public class Main {
    
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
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("This is a Java program to calculate the Weighted Levenshtein distance, with space optimisation and detailed logging.\n\n");
        LevenshteinDistance temp = new LevenshteinDistance();
        
        System.out.print("Enter the number of string pairs you want to process: ");
        int numInputs = scanner.nextInt();
        System.out.println();
        
        for (int i = 1; i <= numInputs; i++) {
            System.out.println("\n\n\n ***** ***** ***** ***** Pair " + i + " ***** ***** ***** ***** \n");
            System.out.print("Enter the first string (The original string): ");
            String str1 = scanner.next();
            System.out.print("Enter the second string (String to convert to): ");
            String str2 = scanner.next();
            
            OperationCosts costs = getCosts();
            
            int res = temp.levenshteinSpaceOptimizedCost(str1, str2, costs);
            
            System.out.println("\n\nMinimum edit distance: " + res);
        }
        
        scanner.close();
    }
}