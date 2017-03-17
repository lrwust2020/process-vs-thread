# process-vs-thread
multi process vs multi thread

## How to use

Just run the script:`test.sh`

```
./test.sh
```

## Custom

You can customize the number of the process/thread,the count and content of the output per process/thread.
Replace the `{process_number},{thread_number},{output_count},{output_content}` in `test.sh`:

```
make
echo -e "MultiProcess process={process_number} count={output_count} output={output_content}" >>result
{ time ./MultiProcess {process_number} {output_count} {output_content};} 2>>result
echo -e "MultiThread thread={thread_number} count={output_count} output={output_content}" >>result
{ time ./MultiThread {thread_number} {output_count} {output_content};} 2>>result
```

## Result

The run time of multi process and thread will be recorded in the file `result`.

```
MultiProcess process=500 count=500 output=测试程序

real	0m2.604s
user	0m0.254s
sys		0m0.622s
MultiThread thread=500 count=500 output=测试程序

real	0m2.275s
user	0m0.260s
sys		0m0.475s
```