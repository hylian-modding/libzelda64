FILES=$(ls *.o)

for i in $FILES ; do
    echo dumping $i
    mips64-objcopy -O binary -j .text $i ./bin/"${i%%.*}".bin
done

