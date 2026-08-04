int findKth(int* nums1, int m, int* nums2, int n, int rank) {
    if (m == 0) {
        return nums2[rank - 1];
    }
    if (n == 0) {
        return nums1[rank - 1];
    }
    if (rank == 1) {
        return (nums1[0] < nums2[0]) ? nums1[0] : nums2[0];
    }

    int half = rank / 2;
    int val1 = (half <= m) ? nums1[half - 1] : INT_MAX;
    int val2 = (half <= n) ? nums2[half - 1] : INT_MAX;

    if (val1 < val2) {
        return findKth(nums1 + half, m - half, nums2, n, rank - half);
    } else {
        return findKth(nums1, m, nums2 + half, n - half, rank - half);
    }
}

double findMedianSortedArrays(int* nums1, int m, int* nums2, int n) {
    int total = m + n;
    int mid1 = findKth(nums1, m, nums2, n, (total + 1) / 2);
    int mid2 = findKth(nums1, m, nums2, n, (total + 2) / 2);
    return (mid1 + mid2) / 2.0;
}