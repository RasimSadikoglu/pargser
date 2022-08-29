#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "../src/pargser.h"

int main() {

    int argc = 10;
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

    int b = 0;
    int i = 0;
    char *s = NULL;
    double d = 0;

    int x = 0;
    int y = 0;

    pargser(argc, argv, "--bool%b;--int%i;--str%s;--double%d;--coordinate%i%i", &b, &i, &s, &d, &x, &y);

    assert(b == 1);
    assert(i == 17);
    assert(!strcmp(s, "abc"));
    assert(d == 19.18);
    assert(x == 13);
    assert(y == 21);
}