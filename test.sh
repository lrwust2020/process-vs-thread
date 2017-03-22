make
echo -e "MultiProcess process=1000 count=500 output=1KB" >>result
{ time ./MultiProcess 1000 500 $(< 1KB);} 2>>result
echo -e "MultiThread thread=1000 count=500 output=1KB" >>result
{ time ./MultiThread 1000 500 $(< 1KB);} 2>>result
