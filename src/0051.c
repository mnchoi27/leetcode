typedef struct {
    char*** ans;
    int* columnSizes;
    int count;
    int buf[9];
    bool cols[9];
    bool adds[17];
    bool subs[17];
} Context;

void record(int n, Context* ctx) {
    char** board = malloc(n * sizeof(char*));

    for (int row = 0; row < n; row++) {
        board[row] = malloc((n + 1) * sizeof(char));

        memset(board[row], '.', n);
        board[row][ctx->buf[row]] = 'Q';
        board[row][n] = '\0';
    }

    ctx->ans[ctx->count] = board;
    ctx->columnSizes[ctx->count] = n;
    ctx->count++;
}

void solve(int n, int row, Context* ctx) {
    if (row == n) {
        record(n, ctx);
        return;
    }

    for (int col = 0; col < n; col++) {
        int add = row + col;
        int sub = row - col + n - 1;

        if (ctx->cols[col] || ctx->adds[add] || ctx->subs[sub]) {
            continue;
        }

        ctx->buf[row] = col;
        ctx->cols[col] = true;
        ctx->adds[add] = true;
        ctx->subs[sub] = true;

        solve(n, row + 1, ctx);

        ctx->cols[col] = false;
        ctx->adds[add] = false;
        ctx->subs[sub] = false;
    }
}

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
    Context ctx = {0};

    ctx.ans = malloc(352 * sizeof(char**));
    ctx.columnSizes = malloc(352 * sizeof(int));

    solve(n, 0, &ctx);

    *returnSize = ctx.count;
    *returnColumnSizes = ctx.columnSizes;

    return ctx.ans;
}