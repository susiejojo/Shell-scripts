#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
extern int errno;
int main()
{
	FILE *fd = fopen("file.txt","r");
	FILE *fp = fopen("new.txt","w");
	char buf;
	if (fd ==NULL)
	{
		perror("Error opening file");
		return (-1);
	}
	fseek(fd,-1,SEEK_END);
	//char buf = fgetc(fd);
	//printf("string at first:%c\n",buf);
	printf("AT start:%ld\n",ftell(fd));
	while (ftell(fd)>0)
	{
		char buf = fgetc(fd);
		fseek(fd,-1,SEEK_CUR);
		printf("string: %c\n",buf);
		printf("after read:%ld\n",ftell(fd));
		fputc(buf,fp);	
		fseek(fd,-1,SEEK_CUR);
	}
	buf = fgetc(fd);
	fseek(fd,-1,SEEK_CUR);
	fputc(buf,fp);
	fclose(fd);
	fclose(fp);
	return 0;
}