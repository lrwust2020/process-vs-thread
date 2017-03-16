#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
 
#define OUTPUT_FILE "output_thread.log"

FILE *outputFile = NULL;

int tNumber = 255; //线程数量，默认255
int count = 100; //每线程打印字符串次数，默认100
char *output = "default output\0"; //输出字符串及默认值

//解析命令行参数
int parseParameter(int argc, char* argv[])
{
	int t = 0, c = 0;
	switch(argc)
	{
		case 1:
		{
			break;
		}
		case 2:
		{
			t = atoi(argv[1]);
			break;
		}
		case 3:
		{
			t = atoi(argv[1]);
			c = atoi(argv[2]);
			break;
		}
		default:
		{
			t = atoi(argv[1]);
			c = atoi(argv[2]);
			output = argv[3];
			break;
		}
	}
	if (t > 0)
		tNumber = t;
	if (c > 0)
		count = c;
	printf("Multi Process Parameters:\n");
	printf("Process Number: %d\n", tNumber);
	printf("Output Count: %d\n", count);
	printf("Output content: %s\n", output);
	return 0;
}

//线程执行的函数
void print_thread_linux() 
{
	for(int i = 0; i < count; i++)
	{
		printf("[%d]%s\n", i, output); //向控制台输出
		fprintf(outputFile, "[%d]%s\n", i, output); //向日志文件输出
	}
	pthread_exit(0); //线程结束 
}
 
int main(int argc, char* argv[])
{
	parseParameter(argc, argv);
	pthread_t pid[tNumber]; //线程数组 
	outputFile = fopen(OUTPUT_FILE, "w+"); //打开日志文件

	for(int i = 0; i < tNumber; i++)
	{
		pthread_create(&pid[i], NULL, (void *)print_thread_linux, NULL); //创建线程
	}

	for(int i = 0; i < tNumber; i++)
	{
		pthread_join(pid[i],NULL); //回收线程
	}

	printf("Finish\n");
	return 0;
}
