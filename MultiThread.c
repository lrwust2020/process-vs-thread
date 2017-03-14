#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
 
#define P_NUMBER 255    //并发线程数量
#define COUNT 100       //每线程打印字符串次数
#define OUTPUT_FILE "output_thread.log"

FILE *outputFile = NULL;
 
char *s = "multi process vs multi thread\0";
 
void print_hello_linux() //线程执行的函数
{
    int i = 0;
    for(i = 0; i < COUNT; i++)
    {
        printf("[%d]%s\n", i, s); //向控制台输出
        fprintf(outputFile, "[%d]%s\n", i, s); //向日志文件输出
    }
    pthread_exit(0); //线程结束 
}
 
int main()
{
    int i = 0;
    pthread_t pid[P_NUMBER]; //线程数组 
    outputFile = fopen(OUTPUT_FILE, "a+"); //打开日志文件
 
    for(i = 0; i < P_NUMBER; i++)
	{
        pthread_create(&pid[i], NULL, (void *)print_hello_linux, NULL); //创建线程
	}
 
    for(i = 0; i < P_NUMBER; i++)
	{
        pthread_join(pid[i],NULL); //回收线程
	}
 
    printf("Finish\n");
    return 0;
}
