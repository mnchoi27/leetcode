int maxArea(int* height, int heightSize) {
    int l = 0;
    int r = heightSize - 1;
    int ans = 0;

    while (l < r) {
        int low = (height[l] < height[r]) ? height[l] : height[r];
        int area = (r - l) * low;

        if (ans < area) {
            ans = area;
        }

        if (height[l] < height[r]) {
            l++;
        } else {
            r--;
        }
    }

    return ans;
}