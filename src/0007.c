int reverse(int x) {
    int s = (x < 0) ? -1 : 1;
    int ans = 0, r;

    if (x == INT_MIN) return 0;
    if (x < 0) x = -x;

    while (x != 0) {
        r = x % 10;
        x /= 10;

        if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && r > INT_MAX % 10))
            return 0;

        ans = ans * 10 + r;
    }

    return s * ans;
}