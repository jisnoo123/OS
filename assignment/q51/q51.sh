c=1
for ((i=1; i<=5; i++))
do
    for ((j=1; j<=i; j++))
    do
        echo -n "$c "
        c=`expr $c + 1`
    done

    echo 
done
