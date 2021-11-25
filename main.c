#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        printf("Error: no arguments supplied\n");
        printf("Usage: %s [-r] <list of strings>\n", argv[0]);
        printf(
            "\t-r specifies 'reverse', meaning it converts keycodes to "
            "strings\n");
        return 1;
    }

    Display *dpy;
    if (!(dpy = XOpenDisplay(0x0))) return 1;

    if (strcmp(argv[1], "-r") == 0) {
        for (int i = 2; i < argc; i++) {
            KeyCode keycode = atoi(argv[i]);
            KeySym keysym = XKeycodeToKeysym(dpy, keycode, 0);
            char *keyString = XKeysymToString(keysym);
            printf("%d: %s\n", keycode, keyString);
        }
    } else {
        for (int i = 1; i < argc; i++) {
            KeyCode code = XKeysymToKeycode(dpy, XStringToKeysym(argv[i]));
            printf("%s: %d\n", argv[i], code);
        }
    }

    return 0;
}
