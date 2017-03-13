#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>

#include "make_log.h"
#define client_file "/etc/fdfs/client.conf.sample"
#define client_path "/home/itheima/object2/fastdfs-5.05/client/fdfs_upload_file" 
#define DEBUG 1

#define __DEBUG(xxx) do
    {
    #if DEBUG 
    printf("%s\n", xxx); 
    #endif    }while(0)





void  __ERROR(int n,char *str)
{
    if(n!=0)
    {
     printf("ERROR %s is FILE: %s len:%d\n",str,__FILE__,__LINE__);
     exit(1);
    }
    return ;
}

int main(int argc,char *argv[])
{
    if (argc<2)
    {
        puts("ERROR main FILEPTAH and FILENAME");
        exit(1);
    }
    pid_t pid;
    int pipfd[2];
    int ret=0;

  //  __DEBUG("123");
    //创建管道
    ret= pipe(pipfd);
    __ERROR(ret,"pipe()");
    
    pid=fork();//创建子进程
    __ERROR(ret,"fork()");
   
    if(pid==0)
    {
      close(pipfd[0]);
      dup2(pipfd[1],STDOUT_FILENO);
      execl(client_path,"fdfs_upload_file",client_file,argv[1],NULL); 
    //execl("/home/itheima/dir/test","test",NULL);
    }
    else
    {
       // sleep(1);
        char buf[1024]={0};
        read(pipfd[0],buf,sizeof(buf));
        printf("父进程收到子进程 %s\n",buf);
       // LOG("");

    }


}

