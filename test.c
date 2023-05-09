#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int i = argc;
    char *arg = argv[1];

    i = 0;
    while (arg[i]) {
        if (arg[i] == ' ') {
            arg[i] = '\0';
            printf("%s\n", &arg[i+1]);
        }
        i++;
    }

    printf("%s\n", arg);

    return 0;
}
