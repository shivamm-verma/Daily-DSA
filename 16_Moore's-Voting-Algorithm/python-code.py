# including all standard libraries (used in competitive programming)


# function for implementing Moore's Voting Algorithm
def moore(arr, n):
    count = 0     #  keep track of current candidate count
    el = None     #  store the potential majority element
    cnt = 0       #  count actual occurrences of candidate

    # Step 1: Finding a candidate for majority element
    for i in range(n):
        if count == 0:
            el = arr[i]  # setting current element as candidate
            count = 1
        elif arr[i] == el:
            count += 1  #if  Same as candidate → increment count
        else:
            count -= 1  # if Different → cancel out

    # Step 2: Verifying the candidate ( really majority?)
    for i in range(n):
        if arr[i] == el:
            cnt += 1

    # Step 3: Check if count > n/2
    if cnt > (n // 2):
        print(f"Majority element is :: {el}")
    else:
        print("No majority element")

# Main function
if __name__ == "__main__":
    # Ask user for array size
    n = int(input("Enter the size of an array :: "))

    # Take array input
    print("Enter the elements for the array :: ", end="")
    arr = list(map(int, input().split()))

    """
     Finding the majority element in the array.
     A majority element is one that appears more than n/2 times.
     We use the efficient Moore's Voting Algorithm for this.
    """
    moore(arr, n)
