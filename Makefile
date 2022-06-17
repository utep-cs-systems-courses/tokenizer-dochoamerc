
OBJS= main.o

#CFLAGS=-g -03

all: reader

reader: $(OBJS)
	cc -o reader $(CFLAGS) $(OBJS)

#$(OBJS):

clean:
	rm -f *.o reader

run:reader
	./reader
