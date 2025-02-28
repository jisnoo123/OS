# Highest command line argument
noc=$#
i=1
rm comm.txt
touch comm.txt
while [ $i -le $noc ]
do
    echo "$1" >> comm.txt
    shift 1
    i=`expr $i + 1`
done

sort -nr comm.txt | head -1