/*
 * @lc app=leetcode.cn id=991 lang=c
 *
 * [991] 坏了的计算器
 */

// @lc code=start

int brokenCalc(int startValue, int target){
    if (startValue >= target) {
        return startValue - target;
    }

    if (startValue * 2 < target) {
        int ts = (target / 2) + (target & 1);
        return brokenCalc(startValue, ts) + 1 + (target & 1);
    } else if (startValue * 2 == target) {
        return 1;
    }

    return ((startValue * 2) - target) / 2 + 1 + (target & 1);
}
// @lc code=end
