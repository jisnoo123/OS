fname=$1
echo >> $fname
cat $fname | tr " " "\n" > word.txt
echo "In alphabetical order:"
sort word.txt

nol=`cat $fname|wc -l`
i=1
while [ $i -le $nol ]
do
    #In a new file place the lines along with their number of words
    line=`cat $fname|head -$i|tail -1`
    nw=`echo $line|wc -w`
    echo "$line|$nw" >> lines.txt
    i=`expr $i + 1`
done
echo "Number of words per line wise:"

sort -t "|" -k2 -n lines.txt > lines_f.txt
cut -d "|" -f1 lines_f.txt 