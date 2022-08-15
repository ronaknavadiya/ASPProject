#include "ftp.h"

char file[1024];

int send_file(char * filename) {

    
    strtok(filename, "\n");
    
    char ch;
	FILE *fp1;
    
    if((fp1 = fopen(filename, "r")) == NULL) {
        if(errno == ENOENT) {
            return 347;
        }
        return 348;
    }
    
    int k = 0;
    ch = fgetc(fp1);
    while (ch != EOF) {
        file[k] = ch;
        k++;
        ch = fgetc(fp1);
    }
    file[k] = '\0';

    return 0;
}