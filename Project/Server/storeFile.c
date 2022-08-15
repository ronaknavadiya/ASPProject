#include "ftp.h"

char file_name[100];
void split(char *pathname)
{

    char splitStrings[10][10];
    int i, j, cnt;

    j = 0;
    cnt = 0;
    for (i = 0; i <= (strlen(pathname)); i++)
    {
        if (pathname[i] == '/' || pathname[i] == '\0')
        {
            splitStrings[cnt][j] = '\0';
            cnt++;
            j = 0;
        }
        else
        {
            splitStrings[cnt][j] = pathname[i];
            j++;
        }
    }
    strcpy(file_name, splitStrings[cnt - 1]);
    file_name[strlen(file_name)] = '\0';
}

int store_file(char *pathname)
{

    char buf[1024];
    char res[1024];
    recv(newSocket, buf, MAXLINE, 0);

    if (strncmp(buf, "NULL", 4) == 0)
    {
        printf(">> It is Invalid File-Name to Store.\n");
        return -1;
    }

    strcpy(res, buf);
    bzero(buf, sizeof(buf));

    split(pathname);
    strtok(pathname, "\n");
    char dest[256];
    getcwd(dest, 256);
    strcat(dest, "/");
    strtok(file_name, "\n");
    strcat(dest, file_name);
    dest[strlen(dest)] = '\0';

    FILE *fp1;
    fp1 = fopen(dest, "w");
    fprintf(fp1, "%s", res);
    fclose(fp1);

    printf("\n File is Received Successfully by client - %s.", USERNAME[count]);
    printf("\n File Name: %s", file_name);

    return 0;
}