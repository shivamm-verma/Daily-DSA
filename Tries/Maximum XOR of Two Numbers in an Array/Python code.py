class Node:
    def __init__(self):
        self.links = [None, None]

    def is_set(self, bit):
        return self.links[bit] is not None

    def get(self, bit):
        return self.links[bit]

    def put(self, bit, node):
        self.links[bit] = node


class Trie:
    def __init__(self):
        self.root = Node()

    def insert(self, num):
        node = self.root
        for i in range(31, -1, -1):
            bit = (num >> i) & 1
            if not node.is_set(bit):
                node.put(bit, Node())
            node = node.get(bit)

    def get_max(self, num):
        node = self.root
        maxi = 0
        for i in range(31, -1, -1):
            bit = (num >> i) & 1
            if node.is_set(1 - bit):
                maxi |= (1 << i)
                node = node.get(1 - bit)
            else:
                node = node.get(bit)
        return maxi


def findMaximumXOR(nums):
    trie = Trie()
    res = 0
    for num in reversed(nums):
        trie.insert(num)
        res = max(res, trie.get_max(num))
    return res


if __name__ == "__main__":
    nums = [3, 10, 5, 25, 2, 8]
    print(findMaximumXOR(nums))  # Output: 28
