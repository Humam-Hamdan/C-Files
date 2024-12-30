main: input.o RAM.o List.o chapters.o main.c
	gcc -std=c17 -Wall main.c List.o RAM.o input.o chapter_*.o -o pointer
	rm *.o
	
RAM.o: RAM.c RAM.h
	gcc -std=c17 -Wall -c RAM.c
	
List.o: PW_standart/List.c PW_standart/List.h
	gcc -std=c17 -Wall -c PW_standart/List.c
	
input.o: PW_standart/input.h PW_standart/input.c
	gcc -std=c17 -Wall -c PW_standart/input.c
	
chapters.o: chapters/chapter_0.c chapters/chapter_1.c chapters/chapter_2.c chapters/chapter_3.c chapters/chapter_4.c chapters/chapter_5.c chapters/chapters.h
	gcc -std=c17 -Wall -c chapters/chapter_0.c chapters/chapter_1.c chapters/chapter_2.c chapters/chapter_3.c chapters/chapter_4.c chapters/chapter_5.c
