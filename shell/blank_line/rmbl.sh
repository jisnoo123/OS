#Remove blank lines from a file
echo "Enter file name:"
read fname
cat $fname| grep -v '^$' > a1
cat a1