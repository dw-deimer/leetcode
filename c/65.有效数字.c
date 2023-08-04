/*
 * @lc app=leetcode.cn id=65 lang=c
 *
 * [65] 有效数字
 */

// @lc code=start
bool isNumber(char * s) {
    int i = 0;
    int e = 0;
    int z = 0;
    int p = 0;
    int n = 0;
    while (i < strlen(s)) {
        char c = s[i++];

        if (isdigit(c)) {
            n++;
            continue;
        }

        if (c == 'e' || c == 'E') {
            if (i == strlen(s) || e || n == 0) {
                return false;
            }
            e = 1;
            z = 0;
            n = 0;
            p = 0;
            continue;
        }

        if (c == '+' || c == '-') {
            if (z || n != 0 || p != 0) {
                return false;
            }
            z = 1;
            continue;
        }

        if (c == '.') {
            if (p || e) {
                return false;
            }
            p = 1;
            continue;
        }

        return false;
    }
    return n != 0;
}
// @lc code=end
