N=5

if [ $# -eq 1 ]; then
    N=$1;
elif [ $# -gt 1 ]; then
    echo "Usage: ${0} [execution count]"
    exit
fi

echo 1 > ex2.txt

for (( i = 1; i <= $N; i++ ))
do
	# race condition usually took place after 6 increments
	./ex2.sh ex2.txt&
	./ex2.sh.sh ex2.txt
done
