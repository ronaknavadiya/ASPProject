#include "ftp.h"

struct stat sta = {0};

int make_directory(char *dir)
{

    strtok(dir, "\n"); // used to remove unnecessary \n at last
    int myStatus = stat(dir, &sta);

    if (myStatus == -1)
    {
        mkdir(dir, 0700);
        return 336;
    }

    if (myStatus == 0)
        return 337;

    return 338;
}