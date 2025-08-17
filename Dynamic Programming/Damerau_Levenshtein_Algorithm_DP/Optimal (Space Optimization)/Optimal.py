class OperationCosts:
    def __init__(self, insert=1, delete=1, replace=1, transpose=1):
        self.insert, self.delete, self.replace, self.transpose = insert, delete, replace, transpose

class DamerauLevenshteinDistance:
    def distance(self, s1, s2, costs=None):
        if costs is None: costs = OperationCosts()
        m, n = len(s1), len(s2)
        if m == 0: return n * costs.insert
        if n == 0: return m * costs.delete
        if m > n:
            swapped = OperationCosts(costs.delete, costs.insert, costs.replace, costs.transpose)
            return self.distance(s2, s1, swapped)
        prev_prev, prev, curr = [0]*(m+1), [i*costs.delete for i in range(m+1)], [0]*(m+1)
        for j in range(1, n+1):
            curr[0] = j * costs.insert
            for i in range(1, m+1):
                if s1[i-1] == s2[j-1]: curr[i] = prev[i-1]
                else:
                    sub = prev[i-1] + costs.replace
                    ins = curr[i-1] + costs.insert
                    dele = prev[i] + costs.delete
                    if i>1 and j>1 and s1[i-1]==s2[j-2] and s1[i-2]==s2[j-1]:
                        trans = prev_prev[i-2] + costs.transpose
                        curr[i] = min(sub, ins, dele, trans)
                    else:
                        curr[i] = min(sub, ins, dele)
            prev_prev, prev = prev, curr[:]
        return prev[m]

if __name__ == "__main__":
    d = DamerauLevenshteinDistance()
    print(d.distance("kitten", "sitting"))  # 3
    print(d.distance("martha", "marhta"))   # 1
