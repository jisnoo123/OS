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

#Reverse

for ((i=0; i<$n/2; i++))
do
    a=${arr[$i]}
    b=${arr[`expr $n - \( $i + 1 \)`]}
    arr[$i]=$b
    arr[`expr $n - \( $i + 1 \)`]=$a
done

#Display new
echo "Reversed array:"
for ((i=0; i<$n; i++))
do
    echo -n "${arr[$i]} "
done
echo