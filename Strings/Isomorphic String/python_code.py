def isIsomorphic(s: str, t: str) -> bool:
    if len(s) != len(t):
        return False

    mapST = {}
    mapTS = {}

    for a, b in zip(s, t):
        if a in mapST and mapST[a] != b:
            return False
        if b in mapTS and mapTS[b] != a:
            return False
        mapST[a] = b
        mapTS[b] = a

    return True

if __name__ == "__main__":
    s = input().strip()
    t = input().strip()
    print("true" if isIsomorphic(s, t) else "false")
