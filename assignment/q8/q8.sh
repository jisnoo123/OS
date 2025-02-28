# find HCF of the pair of consecutive numbers passed as comm line args
hcf()
{
    a=$1
    b=$2

    while [ `expr $b % $a` -ne 0 ]
    do
        r=`expr $b % $a`
        b=$a
        a=$r
    done

    return $a
}

n=$#
for(( i=1; i<$n; i++ ))
do
    hcf $1 $2
    echo "HCF of $1 and $2 is $?"
    shift 1
done