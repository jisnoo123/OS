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

#Search
echo "Enter key:"
read key

low=0
high=`expr $n - 1`


while [ $low -le $high ]
do
    mid=`expr \( $low + $high \) / 2`

    if [ ${arr[$mid]} -eq $key ]
    then    
        echo "$key found at postion $mid"
        break
    elif [ $key -gt ${arr[$mid]} ]
    then
        low=`expr $mid + 1`
    else 
        high=`expr $mid - 1`
    fi

done

if [ $low -gt $high ]
then
    echo "Not found"
fi
