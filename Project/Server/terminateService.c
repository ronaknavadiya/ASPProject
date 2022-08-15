#include "ftp.h"

int exit_service()
{

    srand(time(NULL));
    int no = (rand() % 2);
    if (logged_in)
        printf(">> Client %s is logged out.\n", USERNAME[count]);

    logged_in = false;
    user_done = false;
    if (no == 0)
        return 351;
    return 352;
}

int abort_service()
{

    srand(time(NULL));
    int no = (rand() % 2);
    if (logged_in)
        printf(">> Client %s is  logging out using ABORT.\n", USERNAME[count]);

    logged_in = false;
    user_done = false;
    if (no == 0)
        return 226;

    return 426;
}