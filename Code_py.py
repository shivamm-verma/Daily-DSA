def group_anagrams(strs):
    dic={}
    lst=[]
    for ch in strs:
        val=''.join(sorted(ch))
        if val not in dic:
            dic[val]=[]
        dic[val].append(ch)
    for val in dic.values():
        lst.append(val)
    return lst

if __name__=="__main__":
    strs=input("enter space-seperated strings").split()
    res=group_anagrams(strs)
    print(res)




