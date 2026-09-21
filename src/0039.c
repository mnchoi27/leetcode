typedef struct {
    int** ans;
    int* columnSizes;
    int count;
    int buf[40];
} Context;

void dfs(int* candidates, int candidatesSize, int target, int start, int bufSize, Context* ctx) {
    if (target == 0) {
        ctx->ans[ctx->count] = malloc(bufSize * sizeof(int));
        memcpy(ctx->ans[ctx->count], ctx->buf, bufSize * sizeof(int));
        ctx->columnSizes[ctx->count] = bufSize;
        ctx->count++;
        return;
    }

    for (int i = start; i < candidatesSize; i++) {
        if (candidates[i] > target) {
            continue;
        }

        ctx->buf[bufSize] = candidates[i];
        dfs(candidates, candidatesSize, target - candidates[i], i, bufSize + 1, ctx);
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    Context ctx;

    ctx.ans = malloc(150 * sizeof(int*));
    ctx.columnSizes = malloc(150 * sizeof(int));
    ctx.count = 0;

    dfs(candidates, candidatesSize, target, 0, 0, &ctx);

    *returnSize = ctx.count;
    *returnColumnSizes = ctx.columnSizes;

    return ctx.ans;
}