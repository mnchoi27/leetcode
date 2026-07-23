static const int vs[] = {
    1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1
};
static const char* ss[] = {
    "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"
};

char* intToRoman(int num) {
    static char ans[20];
    ans[0] = '\0';

    for (int i = 0; i < 13; i++) {
        while (num >= vs[i]) {
            num -= vs[i];
            strcat(ans, ss[i]);
        }
    }

    return ans;
}