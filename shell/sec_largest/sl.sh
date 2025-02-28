# Find the second largest line in a file
echo "Enter filename: "
read fname
nol=`cat $fname | wc -l`
i=1
rm edit.txt
touch edit.txt
while [ $i -le $nol ]
do
    str=`cat $fname | head -$i | tail -1`
    nw=`echo "$str"|wc -c`
    echo "$str | $nw" >> edit.txt
    i=`expr $i + 1`
done

sort -t '|' -k2 -nr edit.txt | head -2 | tail -1