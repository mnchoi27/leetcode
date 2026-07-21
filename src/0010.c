char *ss, *pp;

bool dfs(int i, int j) {
    if (pp[j] == '\0') return ss[i] == '\0';

    bool f = ss[i] != '\0' && (pp[j] == '.' || pp[j] == ss[i]);

    if (pp[j + 1] == '*') {
        bool a = dfs(i, j + 2);
        bool b = f && dfs(i + 1, j);
        return a || b;
    }

    return f ? dfs(i + 1, j + 1) : false;
}

bool isMatch(char* s, char* p) {
    ss = s;
    pp = p;
    return dfs(0, 0);
}