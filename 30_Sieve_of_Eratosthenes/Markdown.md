
## ✅ DSA Question: Sieve of Eratosthenes

---

### 🧠 Problem  
Generate all prime numbers up to a given number `n` using the Sieve of Eratosthenes algorithm.

**Examples:**  
- Input: `n = 10` → Output: `[2, 3, 5, 7]`  
- Input: `n = 20` → Output: `[2, 3, 5, 7, 11, 13, 17, 19]`

---

## 🧭 Approach

1. Create a boolean array `isprime` of size `n+1` and initialize all entries as `True`.  
2. Set `isprime[0]` and `isprime[1]` to `False` since 0 and 1 are not primes.  
3. Iterate `i` from `2` to `sqrt(n)`:
   - If `isprime[i]` is `True`, mark all multiples of `i` as `False` starting from `i*i`.  
4. Collect all indices where `isprime[i]` is `True` — these are the prime numbers.

---

## 🔁 Generic Logic (Pseudocode)
```plaintext
function sieveOfEratosthenes(n):
    isprime = array of size n+1 initialized to True
    isprime[0] = False
    isprime[1] = False

    for i from 2 to sqrt(n):
        if isprime[i] == True:
            for j from i*i to n step i:
                isprime[j] = False

    primes = []
    for i from 2 to n:
        if isprime[i] == True:
            primes.append(i)

    return primes
```

---

## ⏱️ Complexities

> Time Complexity  
**O(n log log n)** — due to optimizations using marking multiples efficiently.

> Space Complexity  
**O(n)** — a boolean array of size `n+1` is used.

---
