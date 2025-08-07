#include <stdio.h>
#include <string.h>
#include <limits.h>
int myAtoi(char* s) {
    int i = 0, n = strlen(s), sign = 1, ans = 0;
    while (i < n && s[i] == ' ') {
        i++;
    }
    if (i < n && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }
    while (i < n && s[i] >= '0' && s[i] <= '9') {
        int digit = s[i] - '0';
        if (ans > (INT_MAX - digit) / 10) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        ans = ans * 10 + digit;
        i++;
    }
    return ans * sign;
}
int main() {
    char s[100];
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = 0;
    printf("%d\n", myAtoi(s));
    return 0;
}