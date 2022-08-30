#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "../src/pargser.h"

int main() {

    const char *argv[] = {
        "--bool",
        "--int",
        "17",
        "--str",
        "abc",
        "--double",
        "19.18",
        "--coordinate",
        "13",
        "21"
    };
    int argc = sizeof(argv) / sizeof(*argv);

    int b = 0;
    int i = 0;
    char *s = NULL;
    double d = 0;

    int x = 0;
    int y = 0;

    int b2 = 1;

    pargser(argc, argv, "--bool%b;--int%i;--str%s;--double%d;--coordinate%i%i;--notfound%b;", &b, &i, &s, &d, &x, &y, &b2);

    assert(b == 1);
    assert(i == 17);
    assert(!strcmp(s, "abc"));
    assert(d == 19.18);
    assert(x == 13);
    assert(y == 21);
    assert(b2 == 0);

    printf("Success");
}