class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxWaterVolume = 0;

        int leftPtr = 0, rightPtr = heights.size()-1;

        while(leftPtr < rightPtr) {
            int width = (rightPtr - leftPtr);
            int height = min(heights[leftPtr], heights[rightPtr]);
            int currentWaterVolume = width * height;

            maxWaterVolume = max(currentWaterVolume, maxWaterVolume);

            if (heights[leftPtr] < heights[rightPtr]) {
                ++leftPtr;
            } else {
                --rightPtr;
            }
        }

        return maxWaterVolume;
    }
};
