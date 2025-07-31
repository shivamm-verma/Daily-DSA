def climb_stairs(n):
    if n == 0 or n == 1:
        return 1

    dp = [0] * (n + 1)
    dp[0], dp[1] = 1, 1

    for i in range(2, n + 1):
        dp[i] = dp[i - 1] + dp[i - 2]

    return dp[n]

if __name__ == "__main__":
    n = int(input("Enter the number of steps: "))
    print("The total number of ways are:", climb_stairs(n))
