# Test prime number
echo "Enter a number:"
read n
if [ `factor $n | wc -w` -eq 2 ]
then
    echo "$n is prime"
else
    echo "$n is not prime"
fi