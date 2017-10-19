#include <stdio.h>
#include <stdlib.h>

static void printall(char *str, char *psearch)
{
    for(; *psearch != '\0'; psearch++) {
        if(*psearch != '?')
            continue;

        *psearch = '0';
        printall(str, psearch+1);
        *psearch = '1';
        printall(str, psearch+1);
        *psearch = '?';   // backtrack
        
        return;
    }

    printf("%s\n", str);
}

int main(int argc, char **argv)
{
    char str[40] = "00111?0?1??10";
    //char *str = argv[1];

    printall(str, str);
    return 0;
}
