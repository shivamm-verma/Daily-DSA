#include <bits/stdc++.h>
using namespace std;

pair<int,int> findNumbers(vector<int> &nums) {
    int n = nums.size();
    vector<int> freq(n+1,0);
    int repeating=-1, missing=-1;

    for(int x: nums) freq[x]++;

    for(int i=1;i<=n;i++){
        if(freq[i]==0) missing=i;
        if(freq[i]>1) repeating=i;
    }
    return {repeating, missing};
}

int main() {
    vector<int> nums = {3,1,2,5,3};
    auto ans = findNumbers(nums);
    cout << "Repeating: " << ans.first << ", Missing: " << ans.second << endl;
}
