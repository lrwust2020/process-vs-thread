CFLAGS = -g -Wall --std=gnu99
LDFLAGS = -lpthread

src = $(wildcard *.c)
target = $(patsubst %.c, %, ${src})

.PHONY: all clean

%.o:%.c
	$(CC) ${CFLAGS} -c -o $@
%:%.o
	$(CC) ${LDFLAGS} -o $@

all: ${target}

clean:
	rm -f ${target}
