int trap(int* height, int heightSize) {
    int l = 0;
    int r = heightSize - 1;
    int lMax = 0;
    int rMax = 0;
    int ans = 0;

    while (l < r) {
        if (height[l] < height[r]) {
            if (height[l] > lMax) {
                lMax = height[l];
            } else {
                ans += lMax - height[l];
            }

            l++;
        } else {
            if (height[r] > rMax) {
                rMax = height[r];
            } else {
                ans += rMax - height[r];
            }

            r--;
        }
    }

    return ans;
}