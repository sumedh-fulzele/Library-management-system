
TARGET=main
CSRCS=$(TARGET).c user_dal.c user_service.c user_control.c book_dal.c book_service.c book_control.c
COBJS=$(CSRCS:.c=.o)

CC=gcc
CFLAGS=-Wall
LDFLAGS=

$(TARGET).out: $(COBJS)
	$(CC) $(CFLAGS)  -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -r -f *.o $(TARGET).out

.phony: clean

