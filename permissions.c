#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<errno.h>
#include<string.h>
#include<dirent.h>
#include <sys/stat.h>


extern int errno;
int convertDecimalToOctal(int decimalNumber)
{
    int octalNumber = 0, i = 1;

    while (decimalNumber != 0)
    {
        octalNumber += (decimalNumber % 8) * i;
        decimalNumber /= 8;
        i *= 10;
    }

    return octalNumber;
}

int main (int argc, char* argv[])
{
	DIR* dir = opendir("/home/susiejojo/operating_systems");
	if (dir) {
	    puts("Directory was created");
	    closedir(dir);
	} else if (ENOENT == errno) {
	    puts("Directory does not exist");
	} else {
	    puts("Cannot open directory");
	}
  struct stat  file_stat;

  while (argc-- > 1)
    {
      if (lstat(argv[argc], &file_stat) == -1)
        // fprintf(stderr, "%s\n", strerror(errno));
        write(2,"File not found",13);
      else
        {
	         fprintf(stdout, "%o\t%s\n", file_stat.st_mode,
	                  argv[argc]);
        	 //write(1,file_stat.st_mode,strlen(file_stat.st_mode));
        	 write(1,argv[argc],strlen(argv[argc]));
        	 //write(1,'\n',strlen('\n'));
        	 puts("");
	         char modes[7]="";
	         char modes1[7];
	         //printf("st_mode:%d",file_stat.st_mode);
	         snprintf(modes1,7,"%d",convertDecimalToOctal(file_stat.st_mode));
	         //printf("%s%s\n",modes1,modes);
	         if (strlen(modes1)<6)
	         	strcat(modes,"0");
	         strcat(modes,modes1);
	         //printf("%s\n",modes);
	         char bin_user[4];
	         bin_user[0] = '\0';
	         for(int j = 2; j >= 0; --j)
	        {
	            if(modes[3] & (1 << j))
	             {
	                strcat(bin_user,"1");
	             } 
	             else
	             {
	                strcat(bin_user,"0");
	             }
	        }
		    char bin_grp[4];
	         bin_grp[0] = '\0';
	         for(int j = 2; j >= 0; --j)
	        {
	            if(modes[4] & (1 << j))
	             {
	                strcat(bin_grp,"1");
	             } 
	             else
	             {
	                strcat(bin_grp,"0");
	             }
	        }
	        char bin_oth[4];
	         bin_oth[0] = '\0';
	         for(int j = 2; j >= 0; --j)
	        {
	            if(modes[5] & (1 << j))
	             {
	                strcat(bin_oth,"1");
	             } 
	             else
	             {
	                strcat(bin_oth,"0");
	             }
	        }
	         //printf("User:%s\n",bin_user);
	         if (bin_user[0]=='1')
	         	puts("User has read permission");
	         if (bin_user[1]=='1')
	         	puts("User has write permission");
	         if (bin_user[2]=='1')
	         	puts("User has execute permission");
	         //printf("Grp:%s\n",bin_grp);
	         if (bin_grp[0]=='1')
	         	puts("Group has read permission");
	         if (bin_grp[1]=='1')
	         	puts("Group has write permission");
	         if (bin_grp[2]=='1')
	         	puts("Group has execute permission");
	         //printf("Others:%s\n",bin_oth);
	         if (bin_oth[0]=='1')
	         	puts("Others has read permission");
	         if (bin_oth[1]=='1')
	         	puts("Others has write permission");
	         if (bin_oth[2]=='1')
	         	puts("Others has execute permission");
        }
    }
  return 0;
}