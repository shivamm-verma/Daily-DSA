def merge(intervals):
    # Sort intervals based on starting time
    intervals.sort(key=lambda x: x[0])
    new_intervals = []

    start = intervals[0][0]
    end = intervals[0][1]
    n = len(intervals)

    # If only one interval, return it directly
    if n == 1:
        new_intervals.append(intervals[0])
        return new_intervals

    for i in range(1, n):
        # If intervals overlap
        if intervals[i][0] <= end:
            start = min(start, intervals[i][0])
            end = max(end, intervals[i][1])
        else:
            # No overlap, push the current merged interval
            new_intervals.append([start, end])
            start = intervals[i][0]
            end = intervals[i][1]

    # Add the last interval
    new_intervals.append([start, end])
    return new_intervals


# Driver code
if __name__ == "__main__":
    intervals = [[1, 4], [0, 2], [3, 5]]
    result = merge(intervals)
    for interval in result:
        print(f"[{interval[0]},{interval[1]}]", end="")
