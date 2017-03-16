make
echo -e "MultiProcess process=800 count=5000 output=测试程序" >>result
{ time ./MultiProcess 800 5000 测试程序;} 2>>result
echo -e "MultiThread thread=800 count=5000 output=测试程序" >>result
{ time ./MultiThread 800 5000 测试程序;} 2>>result
