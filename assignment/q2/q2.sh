echo "Enter basic salary:"
read bsal
da=`echo "scale = 4; $bsal * 0.45" | bc`
hra=`echo "scale = 4; $bsal * 0.15" | bc`
ma=500 #Maturity amount(fixed)
tsal=`echo "scale = 4; $bsal + $hra + $da + $ma" | bc`
echo "Total salary is: $tsal"