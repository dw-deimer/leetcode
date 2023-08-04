/*
 * @lc app=leetcode.cn id=599 lang=c
 *
 * [599] 两个列表的最小索引总和
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define min(a, b) ((a) < (b) ? (a) : (b))
char ** findRestaurant(char ** list1, int list1Size, char ** list2, int list2Size, int* returnSize){
    char** ret = malloc(min(list1Size, list2Size) * sizeof(void*));
    for (int s = 0; s < list1Size + list2Size - 1; s++) {
        *returnSize = 0;
        for (int i = 0; i <= min(s, list1Size - 1); i++) {
            if (((s - i) < list2Size) && strcmp(list1[i], list2[s - i]) == 0) {
                ret[*returnSize] = list1[i];
                (*returnSize)++;
            }
        }

        if (*returnSize != 0) {
            return ret;
        }
    }
    free(ret);
    return 0;
}
// @lc code=end
