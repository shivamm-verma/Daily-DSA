public class JavaProgram {
  public int maxArea(int[] height) {
        int left=0, right=height.length-1;
        int area=0, max=0;
        while(left<right)
        {
            area=(right-left)*Math.min(height[left],height[right]);
            max=Math.max(max,area);
            if(height[right]>height[left])
            {
                left++;
            }else
            {
                right--;
            }
        }
        return max;
    }
}

