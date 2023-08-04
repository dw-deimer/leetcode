/*
 * @lc app=leetcode.cn id=2059 lang=c
 *
 * [2059] 转化数字的最小运算数
 */

// @lc code=start

unsigned char nbit[128] = {0};

bool mt(int* xs, int xsSize, int* nums, int numsSize, int * xss, int *xssSize, int t) {
    int c = 0;
    for (int i = 0; i < xsSize; i++) {
        int x = xs[i];
        for (int j = 0; j < numsSize; j++) {
            int n = nums[j];

            int xn = x + n;
            if (xn == t) {
                return true;
            }

            if ((xn>= 0 && xn <= 1000) && ((nbit[xn / 8] & (1 << (xn % 8))) == 0)) {
                nbit[xn / 8] |= (1 << ((xn % 8)));
                xss[c++] = xn;
            }

            xn = x - n;
            if (xn == t) {
                return true;
            }

            if ((xn>= 0 && xn <= 1000) && ((nbit[xn / 8] & (1 << (xn % 8))) == 0)) {
                nbit[xn / 8] |= (1 << (xn % 8));
                xss[c++] = xn;
            }

            xn = x ^ n;
            if (xn == t) {
                return true;
            }

            if ((xn>= 0 && xn <= 1000) && ((nbit[xn / 8] & (1 << (xn % 8))) == 0)) {
                nbit[xn / 8] |= (1 << (xn % 8));
                xss[c++] = xn;
            }
        }
    }
    *xssSize = c;
    return false;
}

int minimumOperations(int* nums, int numsSize, int start, int goal){
    memset(nbit, 0, 128);
    nbit[start / 8] |= (1 << (start % 8));

    int* xs = malloc(numsSize * sizeof(int) * 3);
    int* s = &start;

    int count = 1;
    int size = 0;
    if (mt(s, 1, nums, numsSize, xs, &size, goal)) {
        return count;
    }

    while (size) {
        count++;

        s = xs;
        xs = malloc(size * numsSize * 3 * sizeof(int));
        if (mt(s, size, nums, numsSize, xs, &size, goal)) {
            free(s);
            free(xs);
            return count;
        }

        free(s);
    }
    return -1;
}
// @lc code=end
