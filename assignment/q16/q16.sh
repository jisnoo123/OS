min=$1
max=$min
min_c=`$1|wc -m`
max_c=$min_c
n=$#
i=2
while [ $i -le $n ]
do
    word=$i
    if [ $max_c -gt `echo $word|wc -m` ]
    then
        max=$word
        max_c=`echo $word|wc -m`
    fi

    if [ $min_c -lt `echo $word|wc -m` ]
    then
        min=$word
        min_c=`echo $word|wc -m`
    fi
done
echo "Max is $max"
echo "Min is $min"