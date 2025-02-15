du -a | sort -nr | head -5 > lf.txt # Store the five largest files in lf.txt
cat lf.txt | cut -d '/' -f 2 lf.txt > lff.txt # Seperate the filenames and store in lff.txt
nol=`cat lff.txt|wc -l`
echo number of lines is $nol
mkdir ./backup

i=2
while [ $i -le $nol ]
do
    fname=`cat lff.txt| head -$i | tail -1`
    chmod 777 $fname
    mv $fname backup
    i=`expr $i + 1`
done

cd backup
ls -l