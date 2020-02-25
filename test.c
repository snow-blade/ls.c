#include "tinydir.h"
#include<stdio.h>
int main(int argc,char **argv){
tinydir_dir dir;
tinydir_open(&dir, argv[1]);

while (dir.has_next)
{
	tinydir_file file;
	tinydir_readfile(&dir, &file);
        printf("\033[1;33m");
	printf("%s", file.name);
        printf("\033[0m");
	if (file.is_dir)
	{       
                printf("\033[1;31m");
		printf("/");
                printf("\033[0m");
	}      
	printf("\n");

	tinydir_next(&dir);
}

tinydir_close(&dir);
}
