#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<errno.h>
#include<string.h>
#include<dirent.h>
#include <sys/stat.h>


extern int errno;

int main (int argc, char* argv[])
{
	DIR* dir = opendir("/home/susiejojo/operating_systems");
	if (dir) {
	    printf("Directory was created\n");
	    closedir(dir);
	} else if (ENOENT == errno) {
	    printf("Directory does not exist\n");
	} else {
	    printf("Cannot open directory\n");
	}
  struct stat  file_stat;

  while (argc-- > 1)
    {
      if (lstat(argv[argc], &file_stat) == -1)
        fprintf(stderr, "%s\n", strerror(errno));
      else
        {
	         //fprintf(stdout, "%u\t%s\n", file_stat.st_mode,
	          //        argv[argc]);
	         char modes[6];
	         snprintf(modes,6,"%d",file_stat.st_mode);
	         char bin_user[4];
	         bin_user[0] = '\0';
	         for(int j = 2; j >= 0; --j)
	        {
	            if(modes[2] & (1 << j))
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
	            if(modes[3] & (1 << j))
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
	            if(modes[4] & (1 << j))
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
	         	printf("User has read permission\n");
	         if (bin_user[1]=='1')
	         	printf("User has write permission\n");
	         if (bin_user[2]=='1')
	         	printf("User has execute permission\n");
	         //printf("Grp:%s\n",bin_grp);
	         if (bin_grp[0]=='1')
	         	printf("Group has read permission\n");
	         if (bin_grp[1]=='1')
	         	printf("Group has write permission\n");
	         if (bin_grp[2]=='1')
	         	printf("Group has execute permission\n");
	         //printf("Others:%s\n",bin_oth);
	         if (bin_oth[0]=='1')
	         	printf("Others has read permission\n");
	         if (bin_oth[1]=='1')
	         	printf("Others has write permission\n");
	         if (bin_oth[2]=='1')
	         	printf("Others has execute permission\n");
        }
    }
  return 0;
}