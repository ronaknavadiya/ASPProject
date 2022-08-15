#include "ftpclient.h"

void store_command() {
		
	char myFIle[1024];
	char chars;
	char answer[1024];
	int k = 0;

	for(int i=5; i < strlen(buf); i++) {
		answer[k] = buf[i];
		k++;
	}
	strtok(answer,"\n");


	FILE *fp;
	if((fp = fopen(answer, "r")) != NULL) {
        		
        k = 0;
        chars = fgetc(fp);
    	while (chars != EOF) {
        	myFIle[k] = chars;
        	k++;
        	chars = fgetc(fp);
    	}
    	myFIle[k] = '\0';
    	fclose(fp);
    			
    	printf("Source-File-Path : %s\n", answer);
    	printf("File-Size        : %ld bytes\n", strlen(myFIle));

    	strcpy(buffer, myFIle);
    	send(clientSocket, buffer,MAXLINE, 0);
    	bzero(buffer, sizeof(buffer));
    }
    
    else {
			
		if(errno == ENOENT) {
            printf("Invalid Filename: not exist.\n");
        }
        else
        	printf("Error opening myFIle.\n");
        send(clientSocket, "NULL", 4, 0);
    }
    
}