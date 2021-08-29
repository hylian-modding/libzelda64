#!/bin/bash
# Just execute ./new.sh in the terminal followed by the name of your new actor.
name=$1

cp -r template ${name}
cd ${name}
mv template.c ${name}.c
mv template.h ${name}.h
sed -i s/template/${name}/g Makefile
sed -i s/template.h/${name}.h/g ${name}.c
sed -i s/en_template_t/en_${name}_t/g ${name}.c
sed -i s/en_template_t/en_${name}_t/g ${name}.h
sed -i s/_TEMPLATE__/_${name^^}__/g ${name}.h