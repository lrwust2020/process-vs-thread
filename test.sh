make
(time ./MultiProcess | grep real) >& result
(time ./MultiThread |grep real) >> result 2>&1
