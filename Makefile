CFLAGS += -ansi -Wall -Wextra -Wpedantic -Wwrite-strings -Wno-variadic-macros -Werror -g -Isrc/ -D _XOPEN_SOURCE -D _DEFAULT_SOURCE
SRCS := $(shell find src/ -name '*.c')
OBJS := $(SRCS:.c=.o)

all: rdate
rdate: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -f $(OBJS)
	rm -f rdate
