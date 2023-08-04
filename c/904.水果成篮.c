/*
 * @lc app=leetcode.cn id=904 lang=c
 *
 * [904] 水果成篮
 */

// @lc code=start


int totalFruit(int* fruits, int fruitsSize){
    if (fruitsSize <= 2) {
        return fruitsSize;
    }

    int f1 = fruits[0];
    int f2 = -1;
    int cnt = 1;
    int l = f1;
    int lc = 1;
    int max = 0;

    for (int i = 1; i < fruitsSize; i++) {
        int c = fruits[i];

        if (c == f1 || c == f2) {
            cnt++;

            if (c != l) {
                l = c;
                lc = 1;
            } else {
                lc++;
            }

            continue;
        }

        if (f2 < 0) {
            f2 = c;
            cnt++;
            l = f2;
            lc = 1;
            continue;
        }

        max = max > cnt ? max : cnt;
        f1 = l;
        f2 = c;
        l = c;
        cnt = lc + 1;
        lc = 1;
    }

    max = max > cnt ? max : cnt;
    return max;
}
// @lc code=end
