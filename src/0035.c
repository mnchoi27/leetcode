int searchInsert(int* nums, int numsSize, int target) {
    int lo = 0;
    int hi = numsSize - 1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (nums[mid] == target) {
            return mid;
        }

        if (nums[mid] > target) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return lo;
}