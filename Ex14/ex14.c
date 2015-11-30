#include <stdio.h>
#include <ctype.h>
#include <string.h>

// forward declarations
void print_letters(char arg[], size_t len);
//int can_print_it(char ch);

void print_arguments(int argc, char *argv[]) {

    int i = 0;

    for (i = 0; i < argc; i++) {
        print_letters(argv[i], strlen(argv[i]));
    }

    for (i = 0; i < argc; i++) {
        printf("The arg is '%s' and its length is '%zu'\n", argv[i], strlen(argv[i]));
    }
}

void print_letters(char arg[], size_t len) {

    int i =  0;

    // Without terminator
    for (i = 0; i < len; i++) {
        char ch = arg[i];

        // Removing the function call
        if (isalpha(ch) || isblank(ch)) {
            printf("'%c' == %d ", ch, ch);
        }
    }

//    // With terminator
//    for (i = 0; arg[i] != '\0'; i++) {
//        char ch = arg[i];
//
//        // Removing the function call
//        if (isalpha(ch) || isblank(ch)) {
//            printf("'%c' == %d ", ch, ch);
//        }
//
////        // Original
////        if (can_print_it(ch)) {
////            printf("'%c' == %d ", ch, ch);
////        }
//    }

    printf("\n");
}

//// Original func call from ln. 30
//int can_print_it(char ch) {
//    return isalpha(ch) || isblank(ch);
//}

int main(int argc, char *argv[]) {

//    // Adding 1 to extend argc
//    print_arguments((argc + 1), argv);
    print_arguments((argc), argv);

    int i = 0;

    printf("There were %d args passed to the function \n", argc);

    for (i = 0; i < argc; i++) {
        printf("'%s' is the arg", argv[i]);
        printf("\n");
    }
    return 0;
}