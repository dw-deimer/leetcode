/*
 * @lc app=leetcode.cn id=80 lang=c
 *
 * [80] 删除有序数组中的重复项 II
 */

// @lc code=start


int removeDuplicates(int* nums, int numsSize){
    int f = 0;
    int i = 1, j = 0;
    for (; i < numsSize; i++) {
        if (nums[i] == nums[j]) {
            if (f) {
                continue;
            }
            f = 1;
        } else {
            f = 0;
        }
        j++;

        if (i != j) {
            nums[j] = nums[i];
        }
    }
    return j + 1;
}
// @lc code=end
