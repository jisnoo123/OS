# Compare real numbers
echo "Enter first number:"
read a
echo "Enter second number:"
read b

if [ `echo "$a == $b" | bc` -eq 1 ]
then
    echo "Both are equal"
elif [ `echo "$a > $b" | bc` -eq 1 ]
then
    echo "$a greater"
else
    echo "$b greater"
fi