#include "ftp.h"

char pwdbuf[256];

int show_cwd() {

    if(getcwd(pwdbuf, 256) == NULL) 
        return 342;
    strtok(pwdbuf, "\n");    
    return 343;
}