#include "ftp.h"

/*-----------------------------------------------------------------------------------------------------------------------------*/
char USERNAME[10][100] = {"RONAK1", "URVISH", "MNOPQR", "STUVWX", "YZABCD", "123456", "234567", "345678", "910111", "121314"};
char PASSWORD[10][100] = {"123456", "123456", "456789", "GHIJKL", "987654", "MNOPQR", "151617", "STUVWX", "181920", "YZABCD"};
/*-----------------------------------------------------------------------------------------------------------------------------*/

bool user_done = false;
bool logged_in = false;

int verify_username(char *uname)
{

    // checking USername
    for (int i = 0; i < 10; i++)
    {
        if (strncmp(uname, USERNAME[i], 6) == 0)
        {
            user_done = true;
            count = i;
            return 331;
        }
    }
    return 300;
}

int verify_password(char *pass)
{
    // checking PAssword

    if (strncmp(pass, PASSWORD[count], 6) == 0)
    {
        logged_in = true;
        return 333;
    }
    return 334;
}