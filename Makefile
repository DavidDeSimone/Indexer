CC = gcc
CLFAGS = -g -Wall
LFLAGS = -L.
IFLAGS = -I.

OUTPUT = index
OBJFILES = liblist.o
all: $(OUTPUT)


$(OUTPUT): $(OBJFILES)
	$(CC) $(CFLAGS) $(OBJFILES) $(LFLAGS) -o $(OUTPUT) $(IFLAGS)

$(OBJFILES): listcoll.c
	$(CC) $(CFLAGS) -c listcoll.c -o liblist.o $(IFLAGS)


clean:
	rm *.o $(OUTPUT)
