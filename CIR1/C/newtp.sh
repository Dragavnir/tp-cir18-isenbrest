#!/bin/sh
if [ -f $1 ]
then
	echo "Argument incorrect.\nCeci peut arriver lorsque l'argument saisi est le nom d'un fichier existant dans le répertoire courant, ou lorsque aucun argument n'est saisi."
else
	mkdir $1/
	touch $1/$1.c
	touch $1/$1.h
	touch $1/fonctions.c
	touch $1/Makefile
	echo "$1 : fonctions.o $1.o\n\tgcc fonctions.o $1.o -o $1\nfonctions.o : fonctions.c $1.h\n\tgcc -c fonctions.c\ncrypto.o : $1.c $1.h\n\tgcc -c $1.c\nclean :\n\trm *.o $1" > $1/Makefile
	echo "#include \"$1.h\"\n" > $1/fonctions.c
        echo "#include \"$1.h\"\n\nint main() {\n\t\n\treturn EXIT_SUCCESS;\n}" > $1/$1.c
	echo "#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n#include <errno.h>\n#include <math.h>" > $1/$1.h
	echo "\nTP $1 créé avec succès !\n"
fi
