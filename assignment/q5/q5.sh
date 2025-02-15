fname=$1
cat $fname | tr " " "\n" > textf.txt
echo  >> textf.txt
nol=`cat textf.txt | wc -l`
echo "Total line is $nol"
i=1
while [ $i -le $nol ]
do
    word=`cat textf.txt | head -$i | tail -1`
    noc=`echo $word | wc -m`
    j=1
    rev=""
    while [ $j -le $noc ]
    do  
        c=`echo $word|cut -c $j`
        rev=$c$rev
        j=`expr $j + 1`
    done

    if [ $rev = $word ]
    then
        echo $word
    fi

    i=`expr $i + 1`
done