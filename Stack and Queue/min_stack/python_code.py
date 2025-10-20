class MinStack:
    def __init__(self):
        # main stack for storing all values
        self.stack = []
        # auxiliary stack for tracking minimum values
        self.min_stack = []

    def push(self, val: int) -> None:
        self.stack.append(val)
        # if min_stack is empty or val <= current min, push to min_stack
        if not self.min_stack or val <= self.min_stack[-1]:
            self.min_stack.append(val)

    def pop(self) -> None:
        if not self.stack:
            return None
        val = self.stack.pop()
        # if popped value is current minimum, pop from min_stack as well
        if val == self.min_stack[-1]:
            self.min_stack.pop()
        return val

    def top(self) -> int:
        if not self.stack:
            return None
        return self.stack[-1]

    def getMin(self) -> int:
        if not self.min_stack:
            return None
        return self.min_stack[-1]
