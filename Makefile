
OBJS= main.o src/tokenizer.o src/history.o

#compiler flags. -g for debug, -O3 for optimization
CFLAGS=-g -O3

all: reader

reader: $(OBJS)
	cc -o reader $(CFLAGS) $(OBJS)

clean:
	rm -f $(OBJS) reader

run:reader
	./reader
