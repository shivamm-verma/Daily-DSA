def climbing_stairs(n):
    if n <= 1:
        return 1
    return climbing_stairs(n - 1) + climbing_stairs(n - 2)

if __name__ == "__main__":
    n = int(input("Enter the number of steps: "))
    total_ways = climbing_stairs(n)
    print("The total number of ways are:", total_ways)
