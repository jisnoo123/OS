#Bubble sort

declare -a arr

echo "Enter size of array:"
read n

#Input
echo "Enter the array elements:"
for ((i=0; i<$n; i++))
do
    echo -n "Enter element:"
    read arr[$i]
    echo
done

#Display original
echo "Elements are:"
for ((i=0; i<$n; i++))
do
    echo -n "${arr[$i]} "
done
echo

#Sort

for ((pass=1; pass<=$n; pass++))
do
    for ((j=0; j<$n-$pass; j++))
    do
        if [ ${arr[$j]} -gt ${arr[`expr $j + 1`]} ]
        then
            t=${arr[$j]}
            arr[$j]=${arr[`expr $j + 1`]}
            arr[`expr $j + 1`]=$t
        fi
    done
done

#Display sorted
echo "Sorted:"
for ((i=0; i<$n; i++))
do
    echo -n "${arr[$i]} "
done 

echo