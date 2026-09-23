typedef struct {
    int** ans;
    int* columnSizes;
    int count;
    int buf[8];
    bool used[8];
} Context;

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

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

        if (i > 0 && nums[i] == nums[i - 1] && !ctx->used[i - 1]) {
            continue;
        }

        ctx->used[i] = true;
        ctx->buf[bufSize] = nums[i];
        dfs(nums, numsSize, bufSize + 1, ctx);
        ctx->used[i] = false;
    }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    Context ctx = {0};

    ctx.ans = malloc(40320 * sizeof(int*));
    ctx.columnSizes = malloc(40320 * sizeof(int));

    qsort(nums, numsSize, sizeof(int), cmp);

    dfs(nums, numsSize, 0, &ctx);

    *returnSize = ctx.count;
    *returnColumnSizes = ctx.columnSizes;

    return ctx.ans;
}