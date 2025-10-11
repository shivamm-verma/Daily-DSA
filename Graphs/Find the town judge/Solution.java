class Solution {
    public int findJudge(int n, int[][] trust) {
        int[] outdegree = new int[n + 1];
        int[] indegree = new int[n + 1];

        for (int i = 0; i < trust.length; i++) {
            int source = trust[i][0];
            int destination = trust[i][1];
            outdegree[source] += 1;
            indegree[destination] += 1;
        }

        for (int i = 1; i <= n; i++) {
            if (outdegree[i] == 0 && indegree[i] == n - 1) {
                return i;
            }
        }

        return -1;
    }

    // psvm for testing
    public static void main(String[] args) {
        Solution sol = new Solution();
        int n = 3;
        int[][] trust = {{1, 3}, {2, 3}};
        System.out.println(sol.findJudge(n, trust));  // Output: 3
    }
}
