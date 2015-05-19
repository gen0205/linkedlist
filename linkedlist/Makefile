PROGRAM = wordcount
SRCS += LinkedList.c
SRCS += main.c

OBJS = $(SRCS:%.c=%.o)

.SUFFIXES : .o .c
CC = gcc
CFLAGS = -Wall -O2

all : $(PROGRAM)

clean : 
	rm -f $(PROGRAM) $~ *.o

$(PROGRAM) : $(OBJS)
	$(CC) $^ -o $(PROGRAM)

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<

