class Code:
    def totalFruit(self,fruits):
        n=len(fruits)
        max_fruits=0
        for i in range(n):
            basket=set()
            count=0
            for j in range(i, n):
                basket.add(fruits[j])
                if len(basket)>2:
                    break
                count += 1
            max_fruits = max(max_fruits, count)
        return max_fruits
