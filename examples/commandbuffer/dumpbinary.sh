FILES=$(ls *.o.$1)

for i in $FILES ; do
    echo dumping $i
    mips64-objcopy -O binary -j .text $i ./bin_$1/"${i%%.*}".bin
done

