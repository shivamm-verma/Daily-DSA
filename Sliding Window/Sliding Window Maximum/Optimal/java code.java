import java.util.Deque;
import java.util.ArrayDeque;
import java.util.List;
import java.util.ArrayList;


class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        Deque<Integer> q = new ArrayDeque<>();  // Deque to store indices of elements in decreasing order of values.
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            // Remove indices whose corresponding values are less than or equal to the current value
            // These cannot be the max for this window or any future window
            while (!q.isEmpty() && nums[q.getLast()] <= nums[i]) {
                q.removeLast();
            }
             // Add the current index to the deque
            q.addLast(i);
             // Remove the index at the front if it's outside the current window
            // This ensures that only valid indices (inside the current window) remain
            if (q.getFirst() == i - k) {
                q.removeFirst();
            }
            // Once we've processed at least k elements (i >= k - 1), we can start recording results
            // The front of the deque is the index of the maximum value for the current window
            if (i >= k - 1) {
                res.add(nums[q.peek()]);
            }
        }
        // Convert the result list to an array before returning.
        return res.stream().mapToInt(i->i).toArray();            
    }
}