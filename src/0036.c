bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int rows[9][9] = {0};
    int cols[9][9] = {0};
    int subs[9][9] = {0};

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') {
                continue;
            }

            int digit = board[i][j] - '1';
            int sub = (i / 3) * 3 + j / 3;

            if (rows[i][digit] || cols[j][digit] || subs[sub][digit]) {
                return false;
            }

            rows[i][digit] = 1;
            cols[j][digit] = 1;
            subs[sub][digit] = 1;
        }
    }

    return true;
}