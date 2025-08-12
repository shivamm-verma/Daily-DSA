import java.util.List;
import java.util.PriorityQueue;

class Solution {
    private static class Node {
        int value;
        int listIdx;
        int elemIdx;

        Node(int val, int lIdx, int eIdx) {
            this.value = val;
            this.listIdx = lIdx;
            this.elemIdx = eIdx;
        }
    }

    public int[] smallestRange(List<List<Integer>> nums) {
        PriorityQueue<Node> minHeap = new PriorityQueue<>((a, b) -> a.value - b.value);
        int maxVal = Integer.MIN_VALUE;
        int k = nums.size();

        for (int i = 0; i < k; i++) {
            if (!nums.get(i).isEmpty()) {
                int val = nums.get(i).get(0);
                minHeap.offer(new Node(val, i, 0));
                maxVal = Math.max(maxVal, val);
            }
        }

        int rangeStart = -1;
        int minRangeSize = Integer.MAX_VALUE;

        while (minHeap.size() == k) {
            Node current = minHeap.poll();
            int minVal = current.value;
            int listIdx = current.listIdx;
            int elemIdx = current.elemIdx;

            if (maxVal - minVal < minRangeSize) {
                minRangeSize = maxVal - minVal;
                rangeStart = minVal;
            }

            if (elemIdx + 1 < nums.get(listIdx).size()) {
                int nextVal = nums.get(listIdx).get(elemIdx + 1);
                minHeap.offer(new Node(nextVal, listIdx, elemIdx + 1));
                maxVal = Math.max(maxVal, nextVal);
            } else {
                break;
            }
        }

        return new int[]{rangeStart, rangeStart + minRangeSize};
    }
}