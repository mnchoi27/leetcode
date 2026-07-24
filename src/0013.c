int val(char c) {
    switch (c) {
        case 'M': return 1000;
        case 'D': return 500;
        case 'C': return 100;
        case 'L': return 50;
        case 'X': return 10;
        case 'V': return 5;
        case 'I': return 1;
        default:  return 0;
    }
}

int romanToInt(char* s) {
    int ans = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        int sign = val(s[i]) < val(s[i + 1]) ? -1 : 1;
        ans += sign * val(s[i]);
    }

    return ans;
}