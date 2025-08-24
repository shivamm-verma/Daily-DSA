#include <bits/stdc++.h>
using namespace std;

pair<int,int> findNumbers(vector<int> &nums) {
    long long n = nums.size();
    long long Sn = n*(n+1)/2;
    long long S2n = n*(n+1)*(2*n+1)/6;

    long long S=0, S2=0;
    for(long long x: nums){
        S += x;
        S2 += (long long)x*x;
    }

    long long diff = S - Sn;             // x - y
    long long sqDiff = S2 - S2n;         // x^2 - y^2 = (x-y)(x+y)

    long long sum = sqDiff / diff;       // x + y

    long long x = (diff + sum)/2;
    long long y = x - diff;

    return {(int)x,(int)y};
}

int main() {
    vector<int> nums = {3,1,2,5,3};
    auto ans = findNumbers(nums);
    cout << "Repeating: " << ans.first << ", Missing: " << ans.second << endl;
}
