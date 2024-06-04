class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea=INT_MIN;
        int start=0;
        int end=height.size()-1;

        while(start<end){
            int length=min(height[start],height[end]);
            int breadth=end-start;

            int curr_area=length*breadth;

            maxarea=max(maxarea,curr_area);

            if(height[start]<height[end]){
               start++;
            }

            else{
               end--;
            }

            
        }
        return maxarea;
    }
};

