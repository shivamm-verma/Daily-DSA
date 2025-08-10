package Stack and Queue.CalculatorWithParentheses;

import java.util.*;

public class java_code {
    private int prec(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }
    private void applyOp(Deque<Character> ops, Deque<Integer> nums) {
        char op = ops.removeLast();
        int b = nums.removeLast();
        int a = nums.removeLast();
        int res = 0;
        switch (op) {
            case '+': res = a + b; break;
            case '-': res = a - b; break;
            case '*': res = a * b; break;
            case '/': res = a / b; break; // trunc toward 0
        }
        nums.addLast(res);
    }

    public int calculate(String s) {
        Deque<Character> ops = new ArrayDeque<>();
        Deque<Integer> nums = new ArrayDeque<>();
        int i = 0, n = s.length();
        while (i < n) {
            char c = s.charAt(i);
            if (c == ' ') { i++; continue; }
            if (Character.isDigit(c)) {
                int num = 0;
                while (i < n && Character.isDigit(s.charAt(i))) {
                    num = num * 10 + (s.charAt(i) - '0');
                    i++;
                }
                nums.addLast(num);
                continue;
            }
            if (c == '(') ops.addLast(c);
            else if (c == ')') {
                while (!ops.isEmpty() && ops.peekLast() != '(') applyOp(ops, nums);
                ops.removeLast(); // pop '('
            } else {
                while (!ops.isEmpty() && prec(ops.peekLast()) >= prec(c)) applyOp(ops, nums);
                ops.addLast(c);
            }
            i++;
        }
        while (!ops.isEmpty()) applyOp(ops, nums);
        return nums.peekLast();
    }

    public static void main(String[] args) {
        java_code s = new java_code();
        System.out.println(s.calculate("3+2*2")); // 7
        System.out.println(s.calculate(" (1+(4+5+2)-3)+(6+8) ")); // 23
        System.out.println(s.calculate("14-3/2")); // 13
    }
}