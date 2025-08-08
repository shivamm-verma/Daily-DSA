def sieve_of_eratosthenes(n):
    # Step 1: Create a boolean list where True indicates a prime number
    isprime = [True] * (n + 1)

    # Step 2: 0 and 1 are not prime
    isprime[0] = False
    isprime[1] = False

    # Step 3: Loop from 2 to sqrt(n)
    for i in range(2, int(n ** 0.5) + 1):
        if isprime[i]:
            # Mark all multiples of i as not prime
            for j in range(2, (n // i) + 1):
                isprime[i * j] = False

    # Step 4: Collect all prime numbers
    primes = []
    for i in range(2, n + 1):
        if isprime[i]:
            primes.append(i)
    return primes
