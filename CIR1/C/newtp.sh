#!/bin/sh
if [ -f $1 ]
then
	echo "Aucun argument"
else
	mkdir $1/
	touch $1/$1.c
	touch $1/$1.h
	touch $1/fonctions.c
	touch $1/Makefile
	echo "$1 : fonctions.o $1.o
        gcc fonctions.o $1.o -o $1
fonctions.o : fonctions.c $1.h
        gcc -c fonctions.c
crypto.o : $1.c $1.h
        gcc -c $1.c
clean :
        rm *.o $1" > $1/Makefile
	echo "#include \"$1.h\"\n" > $1/fonctions.c
        echo "#include \"$1.h\"\n" > $1/$1.c
	echo "#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>\n" > $1/$1.h
fi
