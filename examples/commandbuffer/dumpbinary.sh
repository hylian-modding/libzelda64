FILES=$(ls build/src/*.o_$1)

for i in $FILES ; do
    echo dumping $i
    $2objcopy -O binary -j .text $i ./build/bin_$1/"${i%%.*}".bin
done

