bool isValid(char* s) {
    char* top = s;

    for (char* ptr = s; *ptr; ptr++) {
        switch (*ptr) {
            case '(':
                *top++ = ')';
                break;
            case '{':
                *top++ = '}';
                break;
            case '[':
                *top++ = ']';
                break;
            default:
                if (top == s || *--top != *ptr) {
                    return false;
                }
        }
    }

    return top == s;
}