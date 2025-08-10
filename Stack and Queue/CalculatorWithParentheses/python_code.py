class Solution:
    def calculate(self, s: str) -> int:
        def prec(op: str) -> int:
            if op in ('+', '-'): return 1
            if op in ('*', '/'): return 2
            return 0

        def apply_op(ops, nums):
            op = ops.pop()
            b = nums.pop()
            a = nums.pop()
            if op == '+': nums.append(a + b)
            elif op == '-': nums.append(a - b)
            elif op == '*': nums.append(a * b)
            else: nums.append(int(a / b))  # trunc toward 0

        ops = []
        nums = []
        i = 0
        n = len(s)
        while i < n:
            c = s[i]
            if c == ' ':
                i += 1
                continue
            if c.isdigit():
                num = 0
                while i < n and s[i].isdigit():
                    num = num * 10 + (ord(s[i]) - ord('0'))
                    i += 1
                nums.append(num)
                continue
            if c == '(':
                ops.append(c)
            elif c == ')':
                while ops and ops[-1] != '(':
                    apply_op(ops, nums)
                ops.pop()  # pop '('
            else:
                # operator + - * /
                while ops and prec(ops[-1]) >= prec(c):
                    apply_op(ops, nums)
                ops.append(c)
            i += 1

        while ops:
            apply_op(ops, nums)
        return nums[-1]

# quick tests
if __name__ == "__main__":
    sol = Solution()
    print(sol.calculate("3+2*2"))              # 7
    print(sol.calculate(" (1+(4+5+2)-3)+(6+8) "))  # 23
    print(sol.calculate("14-3/2"))             # 13
