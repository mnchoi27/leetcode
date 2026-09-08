bool solve(char** board, int pos, bool rows[9][9], bool cols[9][9], bool subs[9][9]) {
    if (pos == 81) {
        return true;
    }

    int row = pos / 9;
    int col = pos % 9;

    if (board[row][col] != '.') {
        return solve(board, pos + 1, rows, cols, subs);
    }

    int sub = (row / 3) * 3 + col / 3;

    for (int digit = 0; digit < 9; digit++) {
        if (rows[row][digit] || cols[col][digit] || subs[sub][digit]) {
            continue;
        }

        board[row][col] = digit + '1';
        rows[row][digit] = true;
        cols[col][digit] = true;
        subs[sub][digit] = true;

        if (solve(board, pos + 1, rows, cols, subs)) {
            return true;
        }

        board[row][col] = '.';
        rows[row][digit] = false;
        cols[col][digit] = false;
        subs[sub][digit] = false;
    }

    return false;
}

void solveSudoku(char** board, int boardSize, int* boardColSize) {
    bool rows[9][9] = {false};
    bool cols[9][9] = {false};
    bool subs[9][9] = {false};

    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == '.') {
                continue;
            }

            int digit = board[row][col] - '1';
            int sub = (row / 3) * 3 + col / 3;

            rows[row][digit] = true;
            cols[col][digit] = true;
            subs[sub][digit] = true;
        }
    }

    solve(board, 0, rows, cols, subs);
}