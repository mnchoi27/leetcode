const int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
const char* romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

char* intToRoman(int num) {
    char* ans = malloc(16 * sizeof(char));
    int pos = 0;

    for (int i = 0; i < 13 && num > 0; i++) {
        while (num >= values[i]) {
            num -= values[i];
            strcpy(ans + pos, romans[i]);
            pos += strlen(romans[i]);
        }
    }
    ans[pos] = '\0';

    return ans;
}