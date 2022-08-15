#include "ftp.h"

int command = INVALID;
char arg[1024];

void parseCommand(char *buffer)
{

    // Parsing command given by User (CLient)

    command = INVALID;

    while (*buffer == ' ' || *buffer == '\t')
    {
        buffer++;
    }

    if (strncmp(buffer, "USER ", 5) == 0 || strncmp(buffer, "user ", 5) == 0 ||
        strncmp(buffer, "USER\t", 5) == 0 || strncmp(buffer, "user\t", 5) == 0 ||
        strncmp(buffer, "USER\n", 5) == 0 || strncmp(buffer, "user\n", 5) == 0)
    {

        buffer = buffer + 4;
        command = USER;
    }
    else if (strncmp(buffer, "PASS ", 5) == 0 || strncmp(buffer, "pass ", 5) == 0 ||
             strncmp(buffer, "PASS\t", 5) == 0 || strncmp(buffer, "pass\t", 5) == 0 ||
             strncmp(buffer, "PASS\n", 5) == 0 || strncmp(buffer, "pass\n", 5) == 0)
    {

        buffer = buffer + 4;
        command = PASS;
    }
    else if (strncmp(buffer, "MKD ", 4) == 0 || strncmp(buffer, "mkd ", 4) == 0 ||
             strncmp(buffer, "MKD\t", 4) == 0 || strncmp(buffer, "mkd\t", 4) == 0 ||
             strncmp(buffer, "MKD\n", 4) == 0 || strncmp(buffer, "mkd\n", 4) == 0)
    {

        buffer = buffer + 3;
        command = MKD;
    }
    else if (strncmp(buffer, "CWD ", 4) == 0 || strncmp(buffer, "cwd ", 4) == 0 ||
             strncmp(buffer, "CWD\t", 4) == 0 || strncmp(buffer, "cwd\t", 4) == 0 ||
             strncmp(buffer, "CWD\n", 4) == 0 || strncmp(buffer, "cwd\n", 4) == 0)
    {

        buffer = buffer + 3;
        command = CWD;
    }
    else if (strncmp(buffer, "RMD ", 4) == 0 || strncmp(buffer, "rmd ", 4) == 0 ||
             strncmp(buffer, "RMD\t", 4) == 0 || strncmp(buffer, "rmd\t", 4) == 0 ||
             strncmp(buffer, "RMD\n", 4) == 0 || strncmp(buffer, "rmd\n", 4) == 0)
    {

        buffer = buffer + 3;
        command = RMD;
    }
    else if (strncmp(buffer, "PWD ", 4) == 0 || strncmp(buffer, "pwd ", 4) == 0 ||
             strncmp(buffer, "PWD\t", 4) == 0 || strncmp(buffer, "pwd\t", 4) == 0 ||
             strncmp(buffer, "PWD\n", 4) == 0 || strncmp(buffer, "pwd\n", 4) == 0)
    {

        buffer = buffer + 3;
        command = PWD;
    }

    else if (strncmp(buffer, "RETR ", 5) == 0 || strncmp(buffer, "retr ", 5) == 0 ||
             strncmp(buffer, "RETR\t", 5) == 0 || strncmp(buffer, "retr\t", 5) == 0 ||
             strncmp(buffer, "RETR\n", 5) == 0 || strncmp(buffer, "retr\n", 5) == 0)
    {

        buffer = buffer + 4;
        command = RETR;
    }

    else if (strncmp(buffer, "STOR ", 5) == 0 || strncmp(buffer, "stor ", 5) == 0 ||
             strncmp(buffer, "STOR\t", 5) == 0 || strncmp(buffer, "stor\t", 5) == 0 ||
             strncmp(buffer, "STOR\n", 5) == 0 || strncmp(buffer, "stor\n", 5) == 0)
    {

        buffer = buffer + 4;
        command = STOR;
    }

    else if (strncmp(buffer, "LIST ", 5) == 0 || strncmp(buffer, "list ", 5) == 0 ||
             strncmp(buffer, "LIST\t", 5) == 0 || strncmp(buffer, "list\t", 5) == 0 ||
             strncmp(buffer, "LIST\n", 5) == 0 || strncmp(buffer, "list\n", 5) == 0)
    {

        buffer = buffer + 4;
        command = LIST;
    }

    else if (strncmp(buffer, "ABOR ", 5) == 0 || strncmp(buffer, "abor ", 5) == 0 ||
             strncmp(buffer, "ABOR\t", 5) == 0 || strncmp(buffer, "abor\t", 5) == 0 ||
             strncmp(buffer, "ABOR\n", 5) == 0 || strncmp(buffer, "abor\n", 5) == 0)
    {

        buffer = buffer + 4;
        command = ABOR;
    }

    else if (strncmp(buffer, "QUIT ", 5) == 0 || strncmp(buffer, "quit ", 5) == 0 ||
             strncmp(buffer, "QUIT\t", 5) == 0 || strncmp(buffer, "quit\t", 5) == 0 ||
             strncmp(buffer, "QUIT\n", 5) == 0 || strncmp(buffer, "quit\n", 5) == 0)
    {

        buffer = buffer + 4;
        command = QUIT;
    }
    else if (strncmp(buffer, "DELE", 4) == 0)
        command = DELE;

    else if (strncmp(buffer, "HELP", 4) == 0)
        command = HELP;

    else if (strncmp(buffer, "CDUP", 4) == 0)
        command = CDUP;

    else if (strncmp(buffer, "NOOP", 4) == 0)
        command = NOOP;

    while (*buffer == ' ' || *buffer == '\t')
    {
        buffer++;
    }

    strcpy(arg, buffer);
}