#include "ftp.h"

char *reply_message(int status)
{

    if (status == -1)
        return "Reply[450]: Invalid Arguments. Please Try again";

    if (status == 300)
        return "Reply[300]: Please Enter Valid Username.. ";

    if (status == 331)
        return "Reply[200]: Given Command is Valid.\nReply[331]: Username is Valid, Now enter Password..";

    if (status == 332)
        return "Reply[332]: You are already logged in..";

    if (status == 333)
        return "Reply[200]: Given Command is Valid.\nReply[333]: Password is Valid, Logged In.";

    if (status == 334)
        return "Reply[334]: Please Provide Valid Password.";

    if (status == 335)
        return "Reply[335]: Please Enter Username First";

    if (status == 336)
        return "Reply[200]: Given Command is Valid.\nReply[336]: Directory is successfully created.";

    if (status == 337)
        return "Reply[337]: Directory is already exists.";

    if (status == 338)
        return "Reply[338]: Sorry, Directory can't be created. Please Try again.";

    if (status == 503)
        return "Reply[503]: Please enter valid command.";

    if (status == 530)
        return "Reply[530]: Please Log in first";

    if (status == 339)
        return "Reply[339]: EACCES: Permission Denied.";

    if (status == 340)
        return "Reply[340]: ENOTDIR OR ENOENT: Please Enter valid Directory";

    if (status == 341)
        return "Reply[341]: Sorry Couldn't change Directories.";

    if (status == 342)
        return "Reply[342]: Error while fetching CWD-current working directory.";

    if (status == 343)
    {
        static char buffer[256];
        char myMsg[256] = "Reply[200]: Given Command is Valid.\nReply[343]: Remote Working Directory: ";
        split(pwdbuf);
        strcat(myMsg, pwdbuf);
        strcpy(buffer, myMsg);
        strcat(buffer, "\nCurrent-Working-Directory-Name is : ");
        strcat(buffer, file_name);
        return buffer;
    }

    if (status == 344)
        return "Reply[200]: Given Command is Valid.\nReply[344]: Directory has been removed.";

    if (status == 345)
        return "Reply[345]: Directory couldn't be removed(Directory might not exists).";

    if (status == 346)
        return "Reply[346]: Can't open directory";

    if (status == 347)
        return "Reply[347]: Invalid Filename: File does not exist.";

    if (status == 348)
        return "Reply[348]: Can't open file.";

    if (status == 349)
        return "Reply[349]: Not able to write data in socket.";

    if (status == 350)
        return "Reply[350]: Can't read from file.";

    if (status == 226)
        return "Reply[100]: User has been Logged Out.\nReply[226]: Abort cmd has been precessed successfully.";

    if (status == 426)
        return "Reply[551]: Request Action Aborted.\nReply[100]: User Logged Out.\nReply[426]: Service requested aborted abnormally.\nReply[226]: Abort command is successfully processed.";

    if (status == 351)
        return "Reply[351]: Exiting...";

    if (status == 352)
        return "Reply[352]: Data Transfer is In Progress\nReply[351]: Exiting...";

    if (status == 502)
        return "Reply[502]: Not able to find Command.";

    if (status == 600)
        return "Reply[600]: Please Enter the Password.";

    if (status == 535)
        return "Reply[530]: Please Log in first..\nReply[535]: Exiting...";

    return "Reply[504]: Not able to find Command for given parameter.";
}