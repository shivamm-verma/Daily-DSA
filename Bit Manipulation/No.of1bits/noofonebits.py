def noofonebits(n):
    cnt=0
    for i in range(31):
        if n&(1<<i):
            cnt+=1
    return cnt

if __name__=="__main__":
    n=int(input())
    print(noofonebits(n))