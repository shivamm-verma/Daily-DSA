class OperationCosts:
    def __init__(self, insert_cost=1, delete_cost=1, replace_cost=1, transpose_cost=1): 
        self.insert_cost = insert_cost
        self.delete_cost = delete_cost
        self.replace_cost = replace_cost
        self.transpose_cost = transpose_cost 


def get_costs():
    print("\n--- Operation Cost Configuration ---")
    same_cost_choice = int(input("Do all operations have the same cost? (yes=1 / no=0): "))
    
    if same_cost_choice == 1:
        uniform_cost = int(input("Enter the cost for all operations (insert, delete, replace, transpose): ")) 
        print(f"All operations will have cost: {uniform_cost}\n")
        return OperationCosts(uniform_cost, uniform_cost, uniform_cost, uniform_cost)
    else:
        insert_cost = int(input("Enter the cost for insert operation: "))
        delete_cost = int(input("Enter the cost for delete operation: "))
        replace_cost = int(input("Enter the cost for replace operation: "))
        transpose_cost = int(input("Enter the cost for transpose operation: "))  
        
        return OperationCosts(insert_cost, delete_cost, replace_cost, transpose_cost)

class DamerauLevenshteinDistance: 
    
    def _minimum_cost(self, *args):
        """Helper method to find minimum of 2, 3, or 4 values""" 
        return min(*args)
    
    def _print_vector(self, vec, label):
        """Helper method to print vector with formatting"""
        formatted_vec = [f"{x:3d}" for x in vec]
        print(f"{label}: [{','.join(formatted_vec)} ]")
    
    def damerau_levenshtein_space_optimized_cost(self, str1, str2, costs=None):
        """
        DP Vector Method with different operational costs - Return only the cost
        Time Complexity: O(M * N) - traversing over str1 for each letter in str2
        Space Complexity: O(3(min(M,N))) - 3 vectors (prev_prev, prev, curr) for transposition
        NEW: Space complexity increased to handle transposition which requires 3 rows
        """
        
        # Handle default costs
        if costs is None:
            costs = OperationCosts()
        
        m = len(str1)
        n = len(str2)
        
        if m == 0:
            return n * costs.insert_cost
        if n == 0:
            return m * costs.delete_cost
        
        print(f"\nString 1: \"{str1}\" (length: {m})")
        print(f"String 2: \"{str2}\" (length: {n})")
        print(f"Costs - Insert: {costs.insert_cost}, Delete: {costs.delete_cost}, Replace: {costs.replace_cost}, Transpose: {costs.transpose_cost}")
        
        # str1 should be the shorter string for space optimization
        if m > n:
            print("\nSwapping strings for space optimization...")
            swapped_costs = OperationCosts(costs.delete_cost, costs.insert_cost, costs.replace_cost, costs.transpose_cost)
            return self.damerau_levenshtein_space_optimized_cost(str2, str1, swapped_costs)
        
        # Need 3 vectors for transposition (prev_prev, prev, curr)
        prev_prev = [0] * (m + 1)  # Two rows back
        prev = [0] * (m + 1)       # One row back
        curr = [0] * (m + 1)       # Current row
        
        print("\n\nInitializing base cases for deletions:")
        for i in range(m + 1):
            prev[i] = i * costs.delete_cost
        
        print("prev[i] (cost of deleting 'i' characters)")
        self._print_vector(prev, "Initial prev vector")
        
        for j in range(1, n + 1):
            print(f"\n**** Processing column {j} (character '{str2[j-1]}') ****")
            
            curr[0] = j * costs.insert_cost
            print(f"curr[0] = {curr[0]} (cost of inserting {j} characters)")
            
            for i in range(1, m + 1):
                print(f"Comparing '{str1[i-1]}' with '{str2[j-1]}':", end="")
                
                if str1[i-1] == str2[j-1]:
                    curr[i] = prev[i-1]
                    print(f"  MATCH! No cost added. curr[{i}] = prev[{i-1}] = {curr[i]}")
                else:
                    substitute_op = prev[i-1] + costs.replace_cost
                    insert_op = curr[i-1] + costs.insert_cost
                    del_op = prev[i] + costs.delete_cost
                    
                    print("  NO MATCH.", end="")
                    
                    # Check for transposition
                    if (i > 1 and j > 1 and 
                        str1[i-1] == str2[j-2] and str1[i-2] == str2[j-1]):
                        transpose_op = prev_prev[i-2] + costs.transpose_cost
                        curr[i] = self._minimum_cost(substitute_op, insert_op, del_op, transpose_op)
                        
                        print("  TRANSPOSITION POSSIBLE!", end="")
                        print(f"    Minimum cost: {curr[i]}", end="")
                        
                        if curr[i] == transpose_op:
                            print(" (transpose)")
                        elif curr[i] == substitute_op:
                            print(" (substitute_op)")
                        elif curr[i] == insert_op:
                            print(" (insert_op)")
                        else:
                            print(" (delete)")
                    else:
                        curr[i] = self._minimum_cost(substitute_op, insert_op, del_op)
                        print(f"    Minimum cost: {curr[i]}", end="")
                        
                        if curr[i] == substitute_op:
                            print(" (substitute_op)")
                        elif curr[i] == insert_op:
                            print(" (insert_op)")
                        else:
                            print(" (delete)")
            
            self._print_vector(curr, "Current curr vector")
            
            # Shift vectors for next iteration (maintain 3 rows)
            prev_prev = prev.copy()
            prev = curr.copy()
        
        return prev[m]
    
    # Overloaded version with individual cost parameters for backward compatibility
    def damerau_levenshtein_space_optimized_cost_with_params(self, str1, str2, 
                                                           insert_cost=1, delete_cost=1, 
                                                           substitute_cost=1, transpose_cost=1):
        costs = OperationCosts(insert_cost, delete_cost, substitute_cost, transpose_cost)
        return self.damerau_levenshtein_space_optimized_cost(str1, str2, costs)

def main():
    print("This is a Python program to calculate the Weighted Damerau-Levenshtein distance, with space optimization and detailed logging.\n\n")  # Updated description
    
    damerau_levenshtein = DamerauLevenshteinDistance()  
    
    num_inputs = int(input("Enter the number of string pairs you want to process: "))
    print()
    
    for i in range(1, num_inputs + 1):
        print(f"\n\n\n ***** ***** ***** ***** Pair {i} ***** ***** ***** ***** \n")
        
        str1 = input("Enter the first string (The original string): ")
        str2 = input("Enter the second string (String to convert to): ")
        
        costs = get_costs()
        
        result = damerau_levenshtein.damerau_levenshtein_space_optimized_cost(str1, str2, costs)
        
        print(f"\n\nMinimum edit distance: {result}")


if __name__ == "__main__":
    main()
