double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if (nums1Size > nums2Size) {
        int* ta = nums1; nums1 = nums2; nums2 = ta;
        int  ts = nums1Size; nums1Size = nums2Size; nums2Size = ts;
    }

    int m = nums1Size, n = nums2Size;
    int total = m + n;
    int half  = (total + 1) / 2;

    int lo = 0, hi = m;

    while (lo <= hi) {
        int i = (lo + hi) / 2;
        int j = half - i;

        int L1 = (i == 0) ? INT_MIN : nums1[i - 1];
        int R1 = (i == m) ? INT_MAX : nums1[i];
        int L2 = (j == 0) ? INT_MIN : nums2[j - 1];
        int R2 = (j == n) ? INT_MAX : nums2[j];

        if (L1 <= R2 && L2 <= R1) {
            int leftMax = (L1 > L2) ? L1 : L2;
            if (total % 2)
                return (double)leftMax;

            int rightMin = (R1 < R2) ? R1 : R2;
            return (leftMax + rightMin) / 2.0;
        }

        if (L1 > R2) hi = i - 1;
        else lo = i + 1;
    }

    return 0.0;
}