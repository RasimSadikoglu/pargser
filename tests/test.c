#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "../src/pargser.h"

int main() {

    const char *argv[] = {
        "--coordinate",
        "13",
        "21",
        "--int",
        "17",
        "--bool",
        "--double",
        "19.18",
        "--str",
        "abc"
    };
    int argc = sizeof(argv) / sizeof(*argv);

    int b = 0;
    int i = 0;
    char *s = NULL;
    double d = 0;

    int x = 0;
    int y = 0;

    int b2 = 1;

    double notchanged = 13.23;

    pargser(argc, argv, "--bool%b;--int%i;--str%s;--double%d;--coordinate%i%i;--notfound%b;--notchanged%d;", &b, &i, &s, &d, &x, &y, &b2, &notchanged);

    assert(b == 1);
    assert(i == 17);
    assert(!strcmp(s, "abc"));
    assert(d == 19.18);
    assert(x == 13);
    assert(y == 21);
    assert(b2 == 0);
    assert(notchanged == 13.23);

    printf("Success");
}