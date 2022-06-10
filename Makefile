PROVA_TRIMESTRAL: main.o trimestral.o
				  gcc main.o trimestral.o -o PROVA_TRIMESTRAL

main.o: main.c
	    gcc -c main.c

trimestral.o: trimestral.c trimestral.h
		      gcc -c trimestral.c