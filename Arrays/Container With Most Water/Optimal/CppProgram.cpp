class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0, right= height.size()-1;
        int area=0, maxm=0;
        while(left<right)
        {
            area=(right-left)* min(height[left],height[right]);
            maxm= max(maxm,area);
            if(height[right]>height[left])
            {
                left++;
            }else
            {
                right--;
            }
        }
        return maxm;
    }
};