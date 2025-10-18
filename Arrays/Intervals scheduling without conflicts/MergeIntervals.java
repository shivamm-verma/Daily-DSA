import java.util.*;

public class MergeIntervals {

    public static List<int[]> merge(int[][] intervals) {
        // Sort intervals based on starting time
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));

        List<int[]> newIntervals = new ArrayList<>();

        int start = intervals[0][0];
        int end = intervals[0][1];
        int n = intervals.length;

        // If only one interval, return it directly
        if (n == 1) {
            newIntervals.add(new int[]{start, end});
            return newIntervals;
        }

        for (int i = 1; i < n; i++) {
            // If intervals overlap
            if (intervals[i][0] <= end) {
                start = Math.min(start, intervals[i][0]);
                end = Math.max(end, intervals[i][1]);
            } else {
                // No overlap, add the current merged interval
                newIntervals.add(new int[]{start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        // Add the last interval
        newIntervals.add(new int[]{start, end});
        return newIntervals;
    }

    public static void main(String[] args) {
        int[][] intervals = {{1, 4}, {0, 2}, {3, 5}};
        List<int[]> result = merge(intervals);

        for (int[] interval : result) {
            System.out.print("[" + interval[0] + "," + interval[1] + "]");
        }
    }
}