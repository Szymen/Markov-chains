markov: link.o hash.o assoc.o main.c
	cc link.o hash.o assoc.o main.c -ansi -Wall -pedantic -o markov 

assoc.o: assoc_tab.c
	cc -c assoc_tab.c -ansi -Wall -pedantic -o assoc.o

hash.o:	hash.c
	cc -c hash.c -ansi -Wall -pedantic -o hash.o

link.o: linked_list.c
	cc -c  linked_list.c -ansi -Wall -pedantic -o link.o




