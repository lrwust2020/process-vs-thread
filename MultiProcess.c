#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <wait.h>

#define P_NUMBER 255  //并发进程数量 
#define COUNT 100     //每进程打印字符串次数
#define OUTPUT_FILE "output_process.log"

FILE *outputFile = NULL;
 
char *s = "multi process vs multi thread\0";
 
int main()
{
    int i = 0,j = 0;
    outputFile = fopen(OUTPUT_FILE, "a+"); //打开日志文件
    for(i = 0; i < P_NUMBER; i++)
    {
        if(fork() == 0) //创建子进程，if(fork() == 0){}这段代码是子进程运行区间
        {
            for(j = 0;j < COUNT; j++)
            {
                printf("[%d]%s\n", j, s); //向控制台输出
                fprintf(outputFile,"[%d]%s\n", j, s); //向日志文件输出
            }
            exit(0); //子进程结束
        }
    }
 
    for(i = 0; i < P_NUMBER; i++) //回收子进程
    {
        wait(0);
    }
 
    printf("Finish\n");
    return 0;
}
