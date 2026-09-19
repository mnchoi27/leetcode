bool isMatch(char* s, char* p) {
    char* star = NULL;
    char* mark = NULL;

    while (*s) {
        if (*p == '?' || *p == *s) {
            s++;
            p++;
        } else if (*p == '*') {
            star = p;
            mark = s;
            p++;
        } else if (star) {
            mark++;
            s = mark;
            p = star + 1;
        } else {
            return false;
        }
    }

    while (*p == '*') {
        p++;
    }

    return !*p;
}