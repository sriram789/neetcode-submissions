class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxWaterVolume = 0;

        int leftPtr = 0, rightPtr = heights.size()-1;

        while(leftPtr < rightPtr) {
            maxWaterVolume = max((rightPtr - leftPtr) * min(heights[leftPtr], heights[rightPtr]), maxWaterVolume);

            if (heights[leftPtr] < heights[rightPtr]) {
                ++leftPtr;
            } else {
                --rightPtr;
            }
        }

        return maxWaterVolume;
    }
};
