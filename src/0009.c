bool isPalindrome(int x) {
    if (x < 0) return false;

    int n = x, len = 0, r = 0, d;
    while (n != 0) { n /= 10; len++; }

    n = x;
    for (int i = 0; i < len / 2; i++) {
        d = n % 10;
        n /= 10;
        r = r * 10 + d;
    }
    if (len % 2 == 1) n /= 10;

    return n == r;
}