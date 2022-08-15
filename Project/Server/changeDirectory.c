#include "ftp.h"

int change_directory(char *dir)
{
    strtok(dir, "\n");
    if (chdir(dir) == -1)
    {
        if (errno == EACCES)
            return 339;
        else if (errno == ENOTDIR || errno == ENOENT) // ENOENT used when it does not found directory entry
            return 340;
        else
            return 341;
    }
    return 0;
}