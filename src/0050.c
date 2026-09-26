double fastPow(double x, long long n) {
    if (n == 0) {
        return 1.0;
    }

    double half = fastPow(x, n / 2);

    if (n % 2 == 1) {
        return x * half * half;
    } else {
        return half * half;
    }
}

double myPow(double x, int n) {
    if (n < 0) {
        return 1.0 / fastPow(x, -(long long)n);
    }

    return fastPow(x, n);
}