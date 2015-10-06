#include <stdio.h>

/* Decrement Version */
int main(int argc, char *argv[]) {

    // Go through each string in argv
    int i = argc;
    while (i--) {
        printf("arg %d: %s\n", i, argv[i]);
    }

    // Making my own array of strings
    char *progRockBands[] = {
            "Genesis", "Yes",
            "Camel", "Pink Floyd"
    };

    int num_bands = 4;
    i = num_bands;
    while (i--) {
        printf("state %d: %s\n", i, progRockBands[i]);
    }

    return 0;

}

/* Increment Version */
//int main(int argc, char *argv[]) {
//
//    // Go through each string in argv
//    int i = 0;
//    while (i < argc) {
//        printf("arg %d: %s\n", i, argv[i]);
//        i++;
//    }
//
//    // Making my own array of strings
//    char *progRockBands[] = {
//            "Genesis", "Yes",
//            "Camel", "Pink Floyd"
//    };
//
//    int num_bands = 4;
//    i = 0; // watch for this
//    while (i < num_bands) {
//        printf("state %d: %s\n", i, progRockBands[i]);
//        i++;
//    }
//
//    return 0;
//
//}