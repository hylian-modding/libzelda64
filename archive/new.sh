#!/bin/bash
# Just execute ./new.sh in the terminal followed by either "actor", "object", or "both", and the name of your new actor.
WACTOR=false
WOBJECT=false

TYPE=$1
NAME=$2

mkdir ${NAME}

if [ "$TYPE" == "actor" ]
then
    WACTOR=true
fi

if [ "$TYPE" == "object" ]
then
    WOBJECT=true
fi

if [ "$TYPE" == "both" ]
then
    WACTOR=true
    WOBJECT=true
fi

# Actor Directory
if [ "$WACTOR" == true ]
then
    cp -r include/template/actor ${NAME}
    cd ${NAME}/actor
    mv "template.c" ${NAME}.c
    mv "src/template.h" src/${NAME}.h
    sed -i s/template/${NAME}/g Makefile
    sed -i s/template.h/${NAME}.h/g ${NAME}.c
    sed -i s/en_template_t/en_${NAME}_t/g ${NAME}.c
    sed -i s/en_template_t/en_${NAME}_t/g src/${NAME}.h
    sed -i s/_TEMPLATE__/_${NAME^^}__/g src/${NAME}.h
    cd ../../
fi

# Object Directory
if [ "$WOBJECT" == true ]
then
    cp -r include/template/object ${NAME}
    cd ${NAME}/object
    mv "object.c" ${NAME}.c
    sed -i s/OBJ_TEMPLATE_STR/${NAME}/g Makefile
    sed -i s/OBJ_TEMPLATE_STR/${NAME^^}/g src/geometry.h
    sed -i s/OBJ_TEMPLATE_STR/${NAME^^}/g src/textures.h
    cd ../../
fi