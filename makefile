#makefle
.SUFFIXES:
.SUFFIXES: .c.o
VPATH= ./src

#srcfile= $(wildcard *.c)
#obj=$(patsubst %.c,%.o,$(srcfile))


CC=gcc


DIR=./
INC=$(DIR)include/
SRC=$(DIR)src/

object=main.o make_log.o

main:$(object)
	$(CC)  $^ -o $@


#%.o:%c#给我写的怀疑人生了  这.c 都特么要相对路径
#$(obj):$(srcfile)
#.c.o:  老王教的
%.o:%.c
	$(CC) -c -I $(INC) $< -o $@ 


#.c.o:
#main.o:./src/main.c
#	gcc -c -I./include/ ./src/main.c -o main.o
#$(CC) -c -I $(INC) $(SRC)$< -o $@
#make_log.o:./src/make_log.c
#	gcc -c -I./include/ ./src/make_log.c -o make_log.o
	#gcc -c -I ./include/ ./src/ -o 


#gcc -I ../include/  main.c -c -o main.o
#gcc -I /home/itheima/object2/client/include/ /home/itheima/object2/client/src/main.c -o main.o

.PHONY:clean
clean:
	-rm *.o
	-rm main
