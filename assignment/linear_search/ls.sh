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

echo -n "Enter key: "
read key
flag=0
for ((i=0; i<$n; i++))
do
    if [ ${arr[$i]} -eq $key ]
    then
        echo "Found at index $i"
        flag=`expr $flag + 1`
        break
    fi
done

if [ $flag -eq 0 ]
then    
    echo "Not found"
fi