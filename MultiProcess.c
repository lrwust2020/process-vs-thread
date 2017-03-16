#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <wait.h>
   
#define OUTPUT_FILE "output_process.log"

FILE *outputFile = NULL;
 
int pNumber = 255; //并发进程数量，默认255
int count = 100; //每进程打印字符串次数，默认100
char *output = "default output\0"; //输出字符串及默认值

//解析命令行参数
int parseParameter(int argc, char* argv[])
{
	int p = 0, c = 0;
	switch(argc)
	{
		case 1:
		{
			break;
		}
		case 2:
		{
			p = atoi(argv[1]);
			break;
		}
		case 3:
		{
			p = atoi(argv[1]);
			c = atoi(argv[2]);
			break;
		}
		default:
		{
			p = atoi(argv[1]);
			c = atoi(argv[2]);
			output = argv[3];
			break;
		}
	}
	if (p > 0)
		pNumber = p;
	if (c > 0)
		count = c;
	printf("Multi Process Parameters:\n");
	printf("Process Number: %d\n", pNumber);
	printf("Output Count: %d\n", count);
	printf("Output content: %s\n", output);
	return 0;
}
 
int main(int argc, char* argv[])
{
	parseParameter(argc, argv);
	outputFile = fopen(OUTPUT_FILE, "w+"); //打开日志文件
	for(int i = 0; i < pNumber; i++)
	{
		if(fork() == 0) //创建子进程，if(fork() == 0){}这段代码是子进程运行区间
		{
			for(int j = 0;j < count; j++)
			{
				printf("[%d]%s\n", j, output); //向控制台输出
				fprintf(outputFile,"[%d]%s\n", j, output); //向日志文件输出
			}
			exit(0); //子进程结束
		}
	}

	//回收子进程
	for(int i = 0; i < pNumber; i++)
	{
		wait(0);
	}

	printf("Finish\n");
	return 0;
}
