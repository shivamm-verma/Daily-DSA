#include<iostream>
#include<climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int rev=0;
        bool isNegative = false;
        if(x==0)
        return 0;
        if(x<0)
        {
            isNegative = true;
            if(x==INT_MIN)
            return 0;
            x = -x;
        }
        while(x>0)
        {
            int digit = x%10;
            if(rev > INT_MAX/10 || rev==INT_MAX/10 && digit>7)
            return 0;
            rev = rev*10 + digit;
            x = x/10;
        }
        return isNegative? -rev: rev;
    }
};

int main()
{
    Solution sol;
    int ans = sol.reverse(-123);
    cout<<ans<<endl;
    return 0;
}