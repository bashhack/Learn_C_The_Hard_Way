#include <stdio.h>

// Ex11
int main(int argc, char *argv[]) {

    // Go through each string in argv
    int i = 1;
    while (i < argc) {
        printf("arg %d: %s\n", i, argv[i]);
        i++;
    }

    // Making my own array of strings
    char *progRockBands[] = {
            "Genesis", "Yes",
            "Camel", "Pink Floyd"
    };


//    // Re-assignment of arg element to band array element
//    i = 0;
//    while (i < argc) {
//        progRockBands[i] = argv[i];
//        i++;
//    }

    int num_bands = 4;
    i = 0; // watch for this
    while (i < num_bands) {
        // Using if block with break statement to leave loop early
        if (i == 2) {
            break;
        }

        printf("band %d: %s\n", i, progRockBands[i]);
        i++;
    }

    return 0;

}