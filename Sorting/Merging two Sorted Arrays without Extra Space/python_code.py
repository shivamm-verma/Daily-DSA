def mergeArrays(a, b):
    n = len(a)
    m = len(b)
    gap = (n + m + 1) // 2

    while gap > 0:
        i = 0
        j = gap

        while j < n + m:
          
            # If both pointers are in the first array a[]
            if j < n and a[i] > a[j]:
                a[i], a[j] = a[j], a[i]
                
            # If first pointer is in a[] and 
            # the second pointer is in b[]
            elif i < n and j >= n and a[i] > b[j - n]:
                a[i], b[j - n] = b[j - n], a[i]
                
            # Both pointers are in the second array b
            elif i >= n and b[i - n] > b[j - n]:
                b[i - n], b[j - n] = b[j - n], b[i - n]
            i += 1
            j += 1

        # After operating for gap of 1 break the loop
        if gap == 1:
            break

        # Calculate the next gap
        gap = (gap + 1) // 2

if __name__ == "__main__":
    a = [1, 5, 9, 10, 15, 20]
    b = [2, 3, 8, 13]
    mergeArrays(a, b)

    for ele in a:
        print(ele, end=' ')
    print()
    for ele in b:
        print(ele, end=' ')