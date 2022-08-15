#include "ftp.h"

int remove_directory(const char *given_path)
{
	char myPath[256];
	strcpy(myPath, given_path);
	strtok(myPath, "\n");

	DIR *directory = opendir(myPath);
	size_t myPath_len = strlen(myPath);
	int r = -1;

	if (directory)
	{
		struct dirent *dir;
		r = 0;
		while (!r && (dir = readdir(directory)))
		{
			int r2 = -1;
			char *buffer;
			size_t len;

			if (!strcmp(dir->d_name, ".") || !strcmp(dir->d_name, ".."))
				continue;

			len = myPath_len + strlen(dir->d_name) + 2;
			buffer = malloc(len);

			if (buffer)
			{
				struct stat statusBuffer;
				snprintf(buffer, len, "%s/%s", myPath, dir->d_name);

				if (!stat(buffer, &statusBuffer))
				{
					if (S_ISDIR(statusBuffer.st_mode)) // checking wether given name is drectory or not
						r2 = remove_directory(buffer);
					else
						r2 = unlink(buffer);
				}
				else
				{
					if (errno == EACCES)
						return 339;
					else if (errno == ENOTDIR || errno == ENOENT)
						return 340;
					else
						return 341;
				}
				free(buffer);
			}
			r = r2;
		}
		closedir(directory);
	}
	if (!r)
		r = rmdir(myPath);

	return r;
}