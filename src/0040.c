typedef struct {
    int** ans;
    int* columnSizes;
    int count;
    int cap;
    int buf[32];
} Context;

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

void ensureCap(Context* ctx) {
    if (ctx->count < ctx->cap) {
        return;
    }

    int newCap = ctx->cap * 2;

    ctx->ans = realloc(ctx->ans, newCap * sizeof(int*));
    ctx->columnSizes = realloc(ctx->columnSizes, newCap * sizeof(int));
    ctx->cap = newCap;
}

void dfs(int* candidates, int candidatesSize, int target, int start, int bufSize, Context* ctx) {
    if (target == 0) {
        ensureCap(ctx);

        ctx->ans[ctx->count] = malloc(bufSize * sizeof(int));
        memcpy(ctx->ans[ctx->count], ctx->buf, bufSize * sizeof(int));
        ctx->columnSizes[ctx->count] = bufSize;
        ctx->count++;

        return;
    }

    for (int i = start; i < candidatesSize; i++) {
        if (i > start && candidates[i] == candidates[i - 1]) {
            continue;
        }

        if (candidates[i] > target) {
            break;
        }

        ctx->buf[bufSize] = candidates[i];
        dfs(candidates, candidatesSize, target - candidates[i], i + 1, bufSize + 1, ctx);
    }
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    Context ctx;

    ctx.cap = 64;
    ctx.ans = malloc(ctx.cap * sizeof(int*));
    ctx.columnSizes = malloc(ctx.cap * sizeof(int));
    ctx.count = 0;

    qsort(candidates, candidatesSize, sizeof(int), cmp);

    dfs(candidates, candidatesSize, target, 0, 0, &ctx);

    *returnSize = ctx.count;
    *returnColumnSizes = ctx.columnSizes;

    return ctx.ans;
}