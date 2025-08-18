import java.util.*;
class Solution {
    public int minRefuelStops(int target, int startFuel, int[][] stations) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        int n = stations.length;
        int i = 0;
        int curr = startFuel;
        int stops = 0;
        while (curr < target) {
            while (i < n && stations[i][0] <= curr) {
                pq.offer(stations[i][1]);
                i++;
            }
            if (pq.isEmpty()) return -1;
            curr += pq.poll();
            stops++;
        }
        return stops;
    }
    public static void main(String[] args) {
        Solution s = new Solution();
        int[][] stations = {{10,60},{20,30},{30,30},{60,40}};
        System.out.println(s.minRefuelStops(100,10,stations)); // 2
    }
}
