CC=gcc
CFLAGS=-g -Wall
LDFLAGS=-lSDL2

EXEC=launch

SRC = $(wildcard *.c) \
      $(wildcard */*.c)
OBJ=$(SRC:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< 

.PHONY: clean mrproper

clean:
	@rm -rf $(OBJ)

mrproper: clean
	@rm -rf $(EXEC)
