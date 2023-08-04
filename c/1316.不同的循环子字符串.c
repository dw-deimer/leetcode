/*
 * @lc app=leetcode.cn id=1316 lang=c
 *
 * [1316] 不同的循环子字符串
 */

// @lc code=start

int distinctes(char* text, int len) {
    int total = 0;
    int harf = len / 2;

    if (len < 2) {
        return 0;
    } else if (len == 2) {
        if (text[0] == text[1]) {
            return 1;
        }
        return 0;
    } else if (len == 3) {
        if (text[0] == text[1] || text[0] == text[2] || text[1] == text[2]) {
            return 1;
        }
        return 0;
    }

    for (int i = harf; i > 0 ; i--) {
        for (int s1 = 0; s1 <= len - (i * 2); s1++) {
            for (int s2 = s1 + i; s2 <= len - i; s2++) {
                if (memcmp(text + s1, text + s2, i) == 0) {
                    if (i > 1) {
                        total += distinctes(text + s1, i) + 1;
                    } else {
                        total++;
                    }
                    break;
                }
            }
        }
    }
    return total;
}

int distinctEchoSubstrings(char * text) {
    int len = strlen(text);
    return distinctes(text, len);
}
// @lc code=end
