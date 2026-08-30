int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }

    int sign = 1;
    int ans = 0;

    if (dividend > 0) {
        dividend = -dividend;
        sign = -sign;
    }
    if (divisor > 0) {
        divisor = -divisor;
        sign = -sign;
    }

    while (dividend <= divisor) {
        int chunk = divisor;
        int count = -1;

        while (dividend - chunk < chunk) {
            chunk += chunk;
            count += count;
        }

        dividend -= chunk;
        ans += count;
    }

    return (sign > 0) ? -ans : ans;
}