#include "ftp.h"

char list[1024];

int list_directories()
{
    DIR *dir;
    struct dirent *current_dir_entry;
    *list = '\0';

    if (strlen(arg) > 1)
    {
        strtok(arg, "\n");
        if ((dir = opendir(arg)) == NULL)
            return 346;
    }
    else
    {
        if ((dir = opendir("./")) == NULL)
        {
            return 346;
        }
    }

    while ((current_dir_entry = readdir(dir)) != NULL)
    {
        if ((strcmp(current_dir_entry->d_name, ".") != 0) && (strcmp(current_dir_entry->d_name, "..") != 0))
        {
            strcat(list, "-> ");
            strcat(list, current_dir_entry->d_name);
            strcat(list, "\n");
        }
    }
    closedir(dir);
    return 0;
}