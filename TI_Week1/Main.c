#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int i;
    char** arg;

    // The first argument to main() is the number of arguments the
    // program was started with - including the name of the program
    // itself at position 0.
    printf("argc: %d\n", argc);
    // argv[] is an array of pointers to the argument strings. The
    // arguments are at positions 0 to argc-1
    for (i = 0; i < argc; i++)
    {
        printf("Argument %d: %s\n", i, argv[i]);
    }

    // The C standard also guarantees that the argv-array has one
    // additional entry, which has value NULL. So alternatively we can
    // do the following:
    printf("\nThe same via pointers....\n");
    i = 0;
    for (arg = argv; *arg; arg++)
    {
        printf("Argument %d: %s\n", i++, *arg);
    }
    exit(EXIT_SUCCESS);
}