#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<errno.h>
#include<string.h>
extern int errno;
void reverse(char*, int, int);
int main()
{
	int fd = open("file.txt",O_RDONLY);
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	creat("new.txt",mode);
	int fp = open("new.txt",O_RDWR);
	char buf[11];
	if (fd <0)
	{
		perror("Error opening file");
		return (-1);
	}
	lseek(fd,-11,SEEK_END);
	read(fd,buf,10);
	//write(fp,buf,10);	
	//printf("string: %s\n",buf);
	while (lseek(fd,-10,SEEK_CUR)>=0)
	{
		char buf1[11];
		read(fd,buf1,10);	
		lseek(fd,-10,SEEK_CUR);
		reverse(buf1,0,strlen(buf1)-1);
		printf("new string: %s\n",buf1);
		write(fp,buf1,10);	
	}
	char buf2[2];
	while (lseek(fd,-1,SEEK_CUR)>=0)
	{
		read(fd,buf2,1);
		lseek(fd,-1,SEEK_CUR);
		printf("final string: %s\n",buf2);
		write(fp,buf2,1);
	}
	close(fd);
	close(fp);
	return 0;
}
void reverse(char *x, int begin, int end)
{
   char c;
   if (begin >= end)
      return;

   c = *(x+begin);
   *(x+begin) = *(x+end);
   *(x+end)   = c;
   reverse(x, ++begin, --end);
}