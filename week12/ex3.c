//P+E "I passed the Exam!"//
//C+A+P "Get some cappuccino!"//
//J+R "Hello!! Mr. Firas This is Jayveersinh Raj"//

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
       
        while (1){ read(f, &evt, sizeof(evt));
            if (evt.type==EV_KEY){
                if(evt.value>0 && evt.code==25 && 18){
                printf("I passed the Exam!\n");
}                                    
                if (evt.code==46 && 30 && 25 && evt.value>0){
                    printf("Get some cappuccino!\n");
}
                if (evt.code==36 && 19 && evt.value>0){
                    printf("Hello!! Mr. Firas This is Jayveersinh Raj\n");
}
           
            }

            fflush(stdout);
}}
    return EXIT_SUCCESS;
}
 


