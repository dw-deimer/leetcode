/*
 * @lc app=leetcode.cn id=1829 lang=c
 *
 * [1829] 每个查询的最大异或值
 */

// @lc code=start

#include <math.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getMaximumXor(int* nums, int numsSize, int maximumBit, int* returnSize){
    int* ret = malloc(numsSize * sizeof(int));
    int* p = nums;
    int* r = &ret[numsSize-1];

    int x = 0;
    int max = (1 << maximumBit) - 1;
    for (int i = 0; i < numsSize; i++) {
        x ^= *p++;
        *r-- = x ^ max;
    }

    *returnSize = numsSize;
    return ret;
}
// @lc code=end
