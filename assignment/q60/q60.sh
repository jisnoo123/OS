echo "Enter the number of data"
read n

declare -A a
for ((i=0; i<n; i++))
do
    echo -n "Enter data:"
    read a[$i]
    echo
done

echo "Data is:"

for ((i=0; i<n; i++))
do
    echo -n "${a[$i]} "
done

echo

mean=0
var=0
sd=0

for ((i=0; i<n; i++))
do
    mean=`expr $mean + ${a[$i]}`
done

mean=`echo "scale=4; $mean/$n" | bc`

echo "Mean is $mean"
