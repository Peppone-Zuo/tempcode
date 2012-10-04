#include "stdio.h" 
#include "string.h"
#include "math.h"

char pStr[] = "12345";

char * reverse(char *from, char *to) {
    char temp;
    if (from < to) {
        temp = *from;
        *from = *to;
        *to = temp;
        from++;
        to--;
        reverse(from, to);
    }

//    printf("%s", from);
//    temp = getchar();
    return from;
}


int main(void) {
    printf("first %s\n", pStr);
    reverse(pStr, pStr + 4);

    printf("now %s", pStr);

    return 0;
}
