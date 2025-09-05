def can_place(stalls, cows, dist):
    count = 1
    last = stalls[0]
    for i in range(1, len(stalls)):
        if stalls[i] - last >= dist:
            count += 1
            last = stalls[i]
        if count >= cows:
            return True
    return False

def aggressive_cows(stalls, cows):
    stalls.sort()
    ans = 0
    for dist in range(1, stalls[-1] - stalls[0] + 1):
        if can_place(stalls, cows, dist):
            ans = dist
    return ans

stalls = [1, 2, 8, 4, 9]
cows = 3
print(aggressive_cows(stalls, cows))

"""
Time Complexity: O(N * (max(stall) - min(stall)))  
Space Complexity: O(1)
"""
