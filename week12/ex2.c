#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char* dev="/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    int f=open(dev,O_RDONLY);
    if (f<0){
        return EXIT_FAILURE;
    } else{
        struct input_event evt;
        while (1){
            read(f, &evt, sizeof(evt));
            if (evt.type==EV_KEY){
                printf("PRESSED: value %d, code [%d, %x], type %d\n",evt.value,evt.code,evt.code,evt.type);
            }
            fflush(stdout);
        }
    }
    
    return EXIT_SUCCESS;
}
