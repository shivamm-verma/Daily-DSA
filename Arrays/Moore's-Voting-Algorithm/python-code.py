


# function for Moore's Voting Algorithm
def moore(arr, n):
    count = 0     
    el = None     
    cnt = 0      

   
    for i in range(n):
        if count == 0:
            el = arr[i] 
            count = 1
        elif arr[i] == el:
            count += 1  
        else:
            count -= 1 

    for i in range(n):
        if arr[i] == el:
            cnt += 1

    if cnt > (n // 2):
        print(f"Majority element is :: {el}")
    else:
        print("No majority element")


if __name__ == "__main__":
    
    n = int(input("Enter the size of an array :: "))

   
    print("Enter the elements for the array :: ", end="")
    arr = list(map(int, input().split()))


    moore(arr, n)
