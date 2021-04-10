#!/bin/bash
name=d
inputF=input/${name}.txt
outputF=out/${name}_best.out
#./checker input/d.txt out/d_best.out

function timediff() {

# time format:date +"%s.%N", such as 1502758855.907197692
    start_time=$1
    end_time=$2
    
    start_s=${start_time%.*}
    start_nanos=${start_time#*.}
    end_s=${end_time%.*}
    end_nanos=${end_time#*.}
    
    # end_nanos > start_nanos? 
    # Another way, the time part may start with 0, which means
    # it will be regarded as oct format, use "10#" to ensure
    # calculateing with decimal
    if [ "$end_nanos" -lt "$start_nanos" ];then
        end_s=$(( 10#$end_s - 1 ))
        end_nanos=$(( 10#$end_nanos + 10**9 ))
    fi
    
# get timediff
    time=$(( 10#$end_s - 10#$start_s )).$(( (10#$end_nanos - 10#$start_nanos)/10**6 )) 
    echo $time
}

for i in {1..10}
do
    start=$(gdate +"%s.%N")
    ./checker $inputF $outputF 
    end=$(gdate +"%s.%N")
timediff $start $end
done 



# here give the values








