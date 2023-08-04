#include "stdio.h"
#include "string.h"
#include "stdbool.h"
#include "malloc.h"

#include "1316.不同的循环子字符串.c"

int main(int argc, char const *argv[])
{
    int rst = distinctEchoSubstrings("abcabcabc");
    printf("%d\n", rst);
    return 0;
}
