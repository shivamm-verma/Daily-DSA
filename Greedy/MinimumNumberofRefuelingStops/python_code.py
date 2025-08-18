import heapq
class Solution:
    def minRefuelStops(self, target: int, startFuel: int, stations: list[list[int]]) -> int:
        max_heap = []  
        stations.append([target, 0])
        curr = startFuel
        stops = 0
        for pos, fuel in stations:
            while curr < pos:
                if not max_heap:
                    return -1
                curr += -heapq.heappop(max_heap)
                stops += 1
            heapq.heappush(max_heap, -fuel)
        return stops


if __name__ == '__main__':
    sol = Solution()
    print(sol.minRefuelStops(100, 10, [[10,60],[20,30],[30,30],[60,40]]))  # 2