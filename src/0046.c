typedef struct {
    int** ans;
    int* columnSizes;
    int count;
    int buf[6];
    bool used[6];
} Context;

void dfs(int* nums, int numsSize, int bufSize, Context* ctx) {
    if (bufSize == numsSize) {
        ctx->ans[ctx->count] = malloc(bufSize * sizeof(int));
        memcpy(ctx->ans[ctx->count], ctx->buf, bufSize * sizeof(int));
        ctx->columnSizes[ctx->count] = bufSize;
        ctx->count++;
        return;
    }

    for (int i = 0; i < numsSize; i++) {
        if (ctx->used[i]) {
            continue;
        }

        ctx->used[i] = true;
        ctx->buf[bufSize] = nums[i];
        dfs(nums, numsSize, bufSize + 1, ctx);
        ctx->used[i] = false;
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    Context ctx = {0};

    ctx.ans = malloc(720 * sizeof(int*));
    ctx.columnSizes = malloc(720 * sizeof(int));

    dfs(nums, numsSize, 0, &ctx);

    *returnSize = ctx.count;
    *returnColumnSizes = ctx.columnSizes;

    return ctx.ans;
}