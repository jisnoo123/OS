# Shell script to find the largest and smallest word passed as comm line args
n=$#
rm text.txt
touch text.txt
for (( i=1; i<=$n; i++))
do
    nc=`echo $1| wc -c`
    echo "$1 | $nc" >> text.txt
    shift 1
done

sort -t "|" -k2 -nr text.txt >> final.txt
nl=`cat final.txt| wc -l`
max=`cat final.txt| head -1`
min=`cat final.txt| head -$nl| tail -1`
echo "Highest: $max"
echo "Least: $min"