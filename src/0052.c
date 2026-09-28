int solve(int n, int row, bool* cols, bool* adds, bool* subs) {
    if (row == n) {
        return 1;
    }

    int ans = 0;

    for (int col = 0; col < n; col++) {
        int add = row + col;
        int sub = row - col + n - 1;

        if (cols[col] || adds[add] || subs[sub]) {
            continue;
        }

        cols[col] = true;
        adds[add] = true;
        subs[sub] = true;

        ans += solve(n, row + 1, cols, adds, subs);

        cols[col] = false;
        adds[add] = false;
        subs[sub] = false;
    }

    return ans;
}

int totalNQueens(int n) {
    bool cols[9] = {false};
    bool adds[17] = {false};
    bool subs[17] = {false};

    return solve(n, 0, cols, adds, subs);
}