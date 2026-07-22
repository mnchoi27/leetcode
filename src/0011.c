int maxArea(int* height, int heightSize) {
    int l = 0, r = heightSize - 1, ans = 0;

    while (l < r) {
        int h = (height[l] < height[r]) ? height[l] : height[r];
        int t = (r - l) * h;

        if (ans < t) ans = t;

        height[l] < height[r] ? l++ : r--;
    }

    return ans;
}